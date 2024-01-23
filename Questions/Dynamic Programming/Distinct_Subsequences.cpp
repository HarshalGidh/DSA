#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solveUsingRec(string &s, string &t, int i, int j) {
        // Base Case :
        if (j == t.size()) return 1; // all chars matched
        if (i == s.size()) return 0; // couldn't match with t string
        int ans = 0;
        // Check if char match :
        if (s[i] == t[j]) ans += solveUsingRec(s, t, i + 1, j + 1); // include the char
        // Exclude char :
        ans += solveUsingRec(s, t, i + 1, j);
        return ans;
    }

    int solveUsingMem(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        // Base Case :
        if (j == t.size()) return 1; // all chars matched
        if (i == s.size()) return 0; // couldn't match with t string
        // Check if ans is stored, then return ans :
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        // Check if char match :
        if (s[i] == t[j]) ans += solveUsingMem(s, t, i + 1, j + 1, dp); // include the char
        // Exclude char :
        ans += solveUsingMem(s, t, i + 1, j, dp);
        return dp[i][j] = ans;
    }

    int solveUsingTabulation(string &s, string &t) {
        // Create dp array :
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        // Analyze Base Case and fill dp array :
        // we covered the B.C. when i == s.size() then return 0 by initializing dp with 0
        // Now we fill the last col of the dp with 1 when j == t.size()
        for (int row = 0; row <= s.size(); row++) {
            dp[row][t.size()] = 1;
        }
        // Filling the rest of the dp array :
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = t.size() - 1; j >= 0; j--) {
                long long ans = 0; // The test cases are generated so that the answer fits on a
                                   // 32-bit signed integer
                // Check if char match :
                if (s[i] == t[j]) ans += dp[i + 1][j + 1]; // include the char
                // Exclude char :
                ans += dp[i + 1][j];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabulationSO(string &s, string &t) {
        // Create two row arrays :
        // Initialize with row size that is t.size()
        vector<int> nextRow(t.size() + 1, 0);
        vector<int> currRow(t.size() + 1, 0);

        // Analyze Base Case and fill dp array :
        // we covered the B.C. when i == s.size() then return 0 by initializing dp with 0
        // we can't fill the last col while considering rows so we will fill it while going row-wise:

        // Filling the rest of the array :
        // moving row-wise :
        for (int i = s.size() - 1; i >= 0; i--) {
            // fill last col with 1 :
            nextRow[t.size()] = 1;
            for (int j = t.size() - 1; j >= 0; j--) {
                long long ans = 0; // The test cases are generated so that the answer fits on a
                                   // 32-bit signed integer
                // Check if char match :
                if (s[i] == t[j]) ans += nextRow[j + 1]; // include the char
                // Exclude char :
                ans += nextRow[j];
                currRow[j] = ans;
            }
            // shifting :
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int numDistinct(string s, string t) {
        int i = 0, j = 0;
        // return solveUsingRec(s,t,i,j);

        // Create DP array :
        // vector<vector<int> >dp(s.size()+1,vector<int>(t.size()+1,-1));
        // return solveUsingMem(s,t,i,j,dp);

        // return solveUsingTabulation(s,t);

        return solveUsingTabulationSO(s, t);
    }
};

int main() {
    Solution solution;

    // Example 1:
    string s1 = "rabbbit", t1 = "rabbit";
    cout << "Example 1: " << solution.numDistinct(s1, t1) << endl;

    // Example 2:
    string s2 = "babgbag", t2 = "bag";
    cout << "Example 2: " << solution.numDistinct(s2, t2) << endl;

    return 0;
}
