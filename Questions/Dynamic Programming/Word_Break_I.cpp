#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool check(string &word, unordered_set<string> &wordDict) {
        // check if word is present in the wordDict
        return wordDict.find(word) != wordDict.end();
    }

    bool solveUsingRecursion(string &s, unordered_set<string> &wordDict, int start) {
        // Base Case:
        if (start == s.size()) return true;
        bool flag = false;
        string word = "";
        for (int i = start; i < s.size(); i++) {
            word += s[i];
            if (check(word, wordDict)) { // if word is present in the wordDict then :
                flag = flag || solveUsingRecursion(s, wordDict, i + 1);
            }
        }
        return flag;
    }

    bool solveUsingMemo(string &s, unordered_set<string> &wordDict, int start, vector<int> &dp) {
        // Base Case:
        if (start == s.size()) return true;
        if (dp[start] != -1) return dp[start];
        bool flag = false;
        string word = "";
        for (int i = start; i < s.size(); i++) {
            word += s[i];
            if (check(word, wordDict)) { // if word is present in the wordDict then :
                flag = flag || solveUsingMemo(s, wordDict, i + 1, dp);
            }
        }
        return dp[start] = flag;
    }

    bool solveUsingTabulation(string &s, unordered_set<string> &wordDict) {
        // create dp array :
        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = 1; // Initialize the last element with 1

        for (int start = s.size() - 1; start >= 0; start--) {
            bool flag = false;
            string word = "";
            for (int i = start; i < s.size(); i++) {
                word += s[i];
                if (check(word, wordDict)) { // if word is present in the wordDict then :
                    flag = flag || dp[i + 1];
                }
            }
            dp[start] = flag;
        }
        return dp[0] == 1;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int start = 0;
        // return solveUsingRecursion(s, wordSet, start);

        // create dp array :
        // vector<int> dp(s.size() + 1, -1);
        // return solveUsingMemo(s, wordSet, start, dp);

        return solveUsingTabulation(s, wordSet);
    }
};

int main() {
    Solution solution;

    // Example 1:
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << "Example 1: " << (solution.wordBreak(s1, wordDict1) ? "true" : "false") << endl;

    // Example 2:
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << "Example 2: " << (solution.wordBreak(s2, wordDict2) ? "true" : "false") << endl;

    // Example 3:
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Example 3: " << (solution.wordBreak(s3, wordDict3) ? "true" : "false") << endl;

    return 0;
}
