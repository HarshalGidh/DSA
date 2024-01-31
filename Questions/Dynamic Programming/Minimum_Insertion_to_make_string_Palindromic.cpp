#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solveUsingTabulationSO(string &a, string &b) {
        vector<int> curr(a.length() + 1, 0);
        vector<int> next(a.length() + 1, 0);

        // already filled by 0 no need of :dp[a.length() - 1][b.length() - 1] = 0;
        for (int j = b.length() - 1; j >= 0; j--) {
            for (int i = a.length() - 1; i >= 0; i--) {
                int ans = 0;
                // when a common element is found:
                if (a[i] == b[j]) {
                    ans = 1 + next[i + 1];
                } else { // if elements do not match
                    ans = 0 + max(next[i], curr[i + 1]);
                }
                curr[i] = ans;
            }
            // shifting
            next = curr;
        }
        return curr[0];
    }

    int longestPalindromeSubseq(string &s) {
        string a = s;
        reverse(s.begin(), s.end());
        int ans = solveUsingTabulationSO(s, a);
        return ans;
    }

    int minInsertions(string s) {
        int LPS_len = longestPalindromeSubseq(s);
        int ans = s.size() - LPS_len;
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "zzazz";
    int result1 = sol.minInsertions(s1);
    cout << "Output 1: " << result1 << endl;

    // Example 2
    string s2 = "mbadm";
    int result2 = sol.minInsertions(s2);
    cout << "Output 2: " << result2 << endl;

    // Example 3
    string s3 = "leetcode";
    int result3 = sol.minInsertions(s3);
    cout << "Output 3: " << result3 << endl;

    return 0;
}
