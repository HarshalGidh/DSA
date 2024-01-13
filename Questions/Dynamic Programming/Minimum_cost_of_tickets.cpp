#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostTicketsUsingRecursion(vector<int>& days, vector<int>& costs, int i) {
        // Base Case:
        if (i >= days.size()) return 0;

        // Calculate cost for 1-day pass:
        int cost1 = costs[0] + minCostTicketsUsingRecursion(days, costs, i + 1);
        // Calculate cost for 7-day pass:
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        // Calculate the endDay of pass and the next day for which a pass is required:
        while (j < days.size() && days[j] <= passEndDay) {
            j++;
        }
        int cost7 = costs[1] + minCostTicketsUsingRecursion(days, costs, j);

        // Calculate cost for 30-day pass:
        int passEndDay30 = days[i] + 30 - 1;
        int k = i;
        // Calculate the endDay of pass and the next day for which a pass is required:
        while (k < days.size() && days[k] <= passEndDay30) {
            k++;
        }
        int cost30 = costs[2] + minCostTicketsUsingRecursion(days, costs, k);
        int ans = min(cost1, min(cost7, cost30));
        return ans;
    }

    int mincostTicketsUsingTokenization(vector<int>& days, vector<int>& costs) {
        // Create dp array:
        vector<int> dp(days.size() + 1, -1);
        // Analyse and initialise the dp:
        dp[days.size()] = 0;
        for (int i = days.size() - 1; i >= 0; i--) {
            // Calculate cost for 1-day pass:
            int cost1 = costs[0] + dp[i + 1];
            // Calculate cost for 7-day pass:
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            // Calculate the endDay of pass and the next day for which a pass is required:
            while (j < days.size() && days[j] <= passEndDay) {
                j++;
            }
            int cost7 = costs[1] + dp[j];
            // Calculate cost for 30-day pass:
            int passEndDay30 = days[i] + 30 - 1;
            int k = i;
            // Calculate the endDay of pass and the next day for which a pass is required:
            while (k < days.size() && days[k] <= passEndDay30) {
                k++;
            }
            int cost30 = costs[2] + dp[k];
            int ans = min(cost1, min(cost7, cost30));
            dp[i] = ans;
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int ans = minCostTicketsUsingRecursion(days, costs, 0);
        // create dp array:
        // vector<int>dp(days.size() + 1, -1);
        // int ans = minCostUsingMemo(days, costs, 0, dp);
        int ans = mincostTicketsUsingTokenization(days, costs);
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> days1 = {1, 4, 6, 7, 8, 20};
    vector<int> costs1 = {2, 7, 15};
    int result1 = sol.mincostTickets(days1, costs1);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    vector<int> days2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs2 = {2, 7, 15};
    int result2 = sol.mincostTickets(days2, costs2);
    cout << "Example 2: " << result2 << endl;

    return 0;
}
