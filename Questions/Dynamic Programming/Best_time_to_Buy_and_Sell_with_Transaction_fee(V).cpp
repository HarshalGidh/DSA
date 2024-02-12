#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int& fee) {
        // Base Case :
        if (i >= prices.size()) return 0;
        int profit = 0;
        // Buy stock :
        if (buy) {
            int buyProfit = -prices[i] + solve(prices, i + 1, 0, fee); // Considering buy Price as negative
            int skipProfit = solve(prices, i + 1, 1, fee); // skip buying today
            profit = max(buyProfit, skipProfit);
        }
        // Sell Stock :
        else {
            // Minus fee in sell when the transaction is completed
            int sellProfit = prices[i] + solve(prices, i + 1, 1, fee) - fee; // Sell stock and add it to profit
            int skipProfit = solve(prices, i + 1, 0, fee); // Don't sell 
            profit = max(sellProfit, skipProfit);
        }
        return profit;
    }

    int solveTD(vector<int>& prices, int i, int buy, vector<vector<int>>& dp, int& fee) {
        // Base Case :
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        // Buy stock :
        if (buy) {
            int buyProfit = -prices[i] + solveTD(prices, i + 1, 0, dp, fee); // Considering buy Price as negative
            int skipProfit = solveTD(prices, i + 1, 1, dp, fee); // Skip buying today
            profit = max(buyProfit, skipProfit);
        }
        // Sell Stock :
        else {
            int sellProfit = prices[i] + solveTD(prices, i + 1, 1, dp, fee) - fee; // Sell stock and add it to profit
            int skipProfit = solveTD(prices, i + 1, 0, dp, fee); // Don't sell 
            profit = max(sellProfit, skipProfit);
        }
        return dp[i][buy] = profit;
    }

    int solveBU(vector<int>& prices, vector<vector<int>>& dp, int& fee) {
        // Base Case :
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                int profit = 0;
                // Buy stock :
                if (buy) {
                    int buyProfit = -prices[i] + dp[i + 1][0]; // Considering buy Price as negative
                    int skipProfit = dp[i + 1][1]; // Skip buying today
                    profit = max(buyProfit, skipProfit);
                }
                // Sell Stock :
                else {
                    int sellProfit = prices[i] + dp[i + 1][1] - fee; // Sell stock and add it to profit
                    int skipProfit = dp[i + 1][0]; // Don't sell 
                    profit = max(sellProfit, skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSO(vector<int>& prices, vector<vector<int>>& dp, int& fee) {
        // Base Case :
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                int profit = 0;
                // Buy stock :
                if (buy) {
                    int buyProfit = -prices[i] + dp[1][0]; // Considering buy Price as negative
                    int skipProfit = dp[1][1]; // Skip buying today
                    profit = max(buyProfit, skipProfit);
                }
                // Sell Stock :
                else {
                    int sellProfit = prices[i] + dp[1][1] - fee; // Sell stock and add it to profit
                    int skipProfit = dp[1][0]; // Don't sell 
                    profit = max(sellProfit, skipProfit);
                }
                dp[0][buy] = profit;
            }
            // Shifting the row :
            dp[1] = dp[0];
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // return solve(prices, 0, true, fee);

        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return solveTD(prices, 0, true, dp, fee);

        // vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        // return solveBU(prices, dp, fee);

        vector<vector<int>> dp(2, vector<int>(2, 0));
        return solveSO(prices, dp, fee);
    }
};

int main() {
    Solution sol;
    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    int fee1 = 2;
    cout << "Output for prices = [1, 3, 2, 8, 4, 9] and fee = 2: " << sol.maxProfit(prices1, fee1) << endl;

    vector<int> prices2 = {1, 3, 7, 5, 10, 3};
    int fee2 = 3;
    cout << "Output for prices = [1, 3, 7, 5, 10, 3] and fee = 3: " << sol.maxProfit(prices2, fee2) << endl;

    return 0;
}
