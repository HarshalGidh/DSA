#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        for (int i = s1.size() - 1; i >= 0; --i) {
            dp[i][s2.size()] = s1[i] + dp[i + 1][s2.size()];
        }

        for (int i = s2.size() - 1; i >= 0; --i) {
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i + 1];
        }

        int cost = 0;

        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = s2.size() - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    cost = dp[i + 1][j + 1];
                } else {
                    int cost1 = s1[i] + dp[i + 1][j];
                    int cost2 = s2[j] + dp[i][j + 1];
                    cost = min(cost1, cost2);
                }
                dp[i][j] = cost;
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "sea";
    string s2 = "eat";
    int result1 = sol.minimumDeleteSum(s1, s2);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    string s3 = "delete";
    string s4 = "leet";
    int result2 = sol.minimumDeleteSum(s3, s4);
    cout << "Example 2: " << result2 << endl;

    return 0;
}
