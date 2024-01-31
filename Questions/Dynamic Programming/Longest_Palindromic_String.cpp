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
     int solveUsingTabulationSO(string &a, string &b){
         vector<int>curr(a.length() + 1,0);
         vector<int>next(a.length() + 1,0);
         
        // already filled by 0 no need of :dp[a.length() - 1][b.length() - 1] = 0;
        for(int j = b.length() - 1;j>=0;j--){
             for(int i = a.length() - 1;i>=0;i--){
                int ans = 0;
                //when common element is found :
                if(a[i] == b[j]){
                    ans = 1 + next[i+1];
                }
                else{ //if element do not match
                    ans = 0 + max( next[i], curr[i+1] );
                }
                curr[i] = ans;
            }
            //shifting
            next = curr;
        }
        return curr[0] ;
    }
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(s.begin(),s.end());
        int ans = solveUsingTabulationSO(s,a);
        return ans;
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
