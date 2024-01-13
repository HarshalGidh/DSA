#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxLen = 1, start = 0;

    bool isPalindrome(string &s, int i, int j) {
        // Base Case:
        if (i >= j)
            return true;
        bool flag = false;
        if (s[i] == s[j]) {
            flag = isPalindrome(s, i + 1, j - 1);
        }
        if (flag) {
            int currLen = j - i + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
                start = i;
            }
        }
        return flag;
    }

    bool isPalindromeUsingMem(string &s, int i, int j, vector<vector<int>> &dp) {
        // Base Case:
        if (i >= j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        bool flag = false;
        if (s[i] == s[j]) {
            flag = isPalindromeUsingMem(s, i + 1, j - 1, dp);
        }
        if (flag) {
            int currLen = j - i + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool valid = isPalindromeUsingMem(s, i, j, dp);
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;

    // Example
    string s = "babad";
    string result = sol.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
