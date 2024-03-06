#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    void convertStrtoNum(vector<string>& strs, vector<pair<int,int>>& numStrs) {
        for(auto str : strs) {
            int zeros = 0, ones = 0;
            for(auto ch : str) {
                if(ch == '0') zeros++;
                else ones++;
            }
            numStrs.push_back({zeros, ones});
        }
    }
    
    int solve(vector<pair<int,int>>& numStrs, int i, int m, int n) {
        // Base Case:
        if(i == numStrs.size()) return 0;

        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        // If included:
        if(m - zeros >= 0 && n - ones >= 0)
            include = 1 + solve(numStrs, i+1, m - zeros, n - ones);
        exclude = solve(numStrs, i+1, m, n);
        return max(include, exclude); // Return max substr
    }

    int solveTD(vector<pair<int,int>>& numStrs, int i, int m, int n, vector<vector<vector<int>>>& dp) {
        // Base Case:
        if(i == numStrs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        // If included:
        if(m - zeros >= 0 && n - ones >= 0)
            include = 1 + solveTD(numStrs, i+1, m - zeros, n - ones, dp);
        exclude = solveTD(numStrs, i+1, m, n, dp);
        return dp[i][m][n] = max(include, exclude); // Return max substr
    }

    int solveBU(vector<pair<int,int>>& numStrs, int i, int m, int n) {
        vector<vector<vector<int>>> dp(numStrs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for(int i = numStrs.size()-1; i >= 0; i--) {
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {
                    int zeros = numStrs[i].first;
                    int ones = numStrs[i].second;
                    int include = 0, exclude = 0;
                    // If included:
                    if(j - zeros >= 0 && k - ones >= 0)
                        include = 1 + dp[i+1][j - zeros][k - ones];
                    exclude = dp[i+1][j][k];
                    dp[i][j][k] = max(include, exclude); // Return max substr
                }
            }
        }
        return dp[0][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // Creating a vector of pairs containing number of 0s and 1s of all str in strs:
        vector<pair<int,int>> numStrs;
        // Convert str into 0s and 1s:
        convertStrtoNum(strs, numStrs);

        // return solve(numStrs, 0, m, n);

        // vector<vector<vector<int>>> dp(numStrs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        // return solveTD(numStrs, 0, m, n, dp);

        return solveBU(numStrs, 0, m, n);
    }
};

int main() {
    Solution sol;
    vector<string> strs1 = {"10", "0001", "111001", "1", "0"};
    int m1 = 5, n1 = 3;
    cout << "Example 1 Output: " << sol.findMaxForm(strs1, m1, n1) << endl;

    vector<string> strs2 = {"10", "0", "1"};
    int m2 = 1, n2 = 1;
    cout << "Example 2 Output: " << sol.findMaxForm(strs2, m2, n2) << endl;

    // Additional Test Cases
    vector<string> strs3 = {"111", "1000", "1000", "1000"};
    int m3 = 9, n3 = 3;
    cout << "Additional Test Case 1 Output: " << sol.findMaxForm(strs3, m3, n3) << endl;

    vector<string> strs4 = {"10", "01", "001", "0001", "00001"};
    int m4 = 3, n4 = 5;
    cout << "Additional Test Case 2 Output: " << sol.findMaxForm(strs4, m4, n4) << endl;

    return 0;
}

