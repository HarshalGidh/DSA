#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int limit) {
        // Base Case :
        if (i >= prices.size()) return 0;
        if (limit == 0) return 0;
        int profit = 0;
        // Buy stock :
        if (buy) {
            int buyProfit = -prices[i] + solve(prices, i + 1, 0, limit); // Considering buy Price as negative
            int skipProfit = solve(prices, i + 1, 1, limit); // skip buying today
            profit = max(buyProfit, skipProfit);
        }
        // Sell Stock :
        else {
            // Decrease limit by 1 as while selling a transaction pair is completed
            int sellProfit = prices[i] + solve(prices, i + 1, 1, limit - 1); // sell stock and add it to profit
            int skipProfit = solve(prices, i + 1, 0, limit); // don't sell, don't decrement limit here as no sell
            profit = max(sellProfit, skipProfit);
        }
        return profit;
    }

    int solveTD(vector<int>& prices, int i, int buy, int limit, vector<vector<vector<int>>>& dp) {
        // Base Case :
        if (i >= prices.size() || limit == 0) return 0;
        if (dp[i][buy][limit] != -1) return dp[i][buy][limit];
        int profit = 0;
        // Buy stock :
        if (buy) {
            int buyProfit = -prices[i] + solveTD(prices, i + 1, 0, limit, dp); // Considering buy Price as negative
            int skipProfit = solveTD(prices, i + 1, 1, limit, dp); // skip buying today
            profit = max(buyProfit, skipProfit);
        }
        // Sell Stock :
        else {
            // Decrease limit by 1 as while selling a transaction pair is completed
            int sellProfit = prices[i] + solveTD(prices, i + 1, 1, limit - 1, dp); // sell stock and add it to profit
            int skipProfit = solveTD(prices, i + 1, 0, limit, dp); // don't sell, don't decrement limit here as no sell
            profit = max(sellProfit, skipProfit);
        }
        return dp[i][buy][limit] = profit;
    }

    int solveBU(vector<int>& prices, vector<vector<vector<int>>>& dp, int k) {
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int limit = 1; limit < k + 1; limit++) {
                    int profit = 0;
                    // Buy stock :
                    if (buy) {
                        int buyProfit = -prices[i] + dp[i + 1][0][limit]; // Considering buy Price as negative
                        int skipProfit = dp[i + 1][1][limit]; // skip buying today
                        profit = max(buyProfit, skipProfit);
                    }
                    // Sell Stock :
                    else {
                        // Decrease limit by 1 as while selling a transaction pair is completed
                        int sellProfit = prices[i] + dp[i + 1][1][limit - 1]; // sell stock and add it to profit
                        int skipProfit = dp[i + 1][0][limit]; // don't sell, don't decrement limit here as no sell
                        profit = max(sellProfit, skipProfit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }

    int solveSO(vector<int>& prices, vector<vector<vector<int>>>& dp, int k) {
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int limit = 1; limit < k + 1; limit++) {
                    int profit = 0;
                    // Buy stock :
                    if (buy) {
                        int buyProfit = -prices[i] + dp[1][0][limit]; // Considering buy Price as negative
                        int skipProfit = dp[1][1][limit]; // skip buying today
                        profit = max(buyProfit, skipProfit);
                    }
                    // Sell Stock :
                    else {
                        // Decrease limit by 1 as while selling a transaction pair is completed
                        int sellProfit = prices[i] + dp[1][1][limit - 1]; // sell stock and add it to profit
                        int skipProfit = dp[1][0][limit]; // don't sell, don't decrement limit here as no sell
                        profit = max(sellProfit, skipProfit);
                    }
                    dp[0][buy][limit] = profit;
                }
            }
            // Shifting rows :
            dp[1] = dp[0];
        }
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        // return solve(prices, 0, true, k);

        // Create 3d dp :
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        // return solveTD(prices, 0, true, k, dp);

        // Create 3d dp :
        // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        // return solveBU(prices, dp, k);

        // Create 3d dp :
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        return solveSO(prices, dp, k);
    }
};

int main() {
    Solution sol;
    int k1 = 2;
    vector<int> prices1 = {2, 4, 1};
    cout << "Max profit for k = 2 and prices = [2, 4, 1]: " << sol.maxProfit(k1, prices1) << endl;

    int k2 = 2;
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    cout << "Max profit for k = 2 and prices = [3, 2, 6, 5, 0, 3]: " << sol.maxProfit(k2, prices2) << endl;

    return 0;
}
