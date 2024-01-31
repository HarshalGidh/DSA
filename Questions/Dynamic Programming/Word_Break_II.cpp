#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Top-down dynamic programming
    vector<string> solveUsingRecursion(string s, unordered_map<string, bool> &dict, int i, unordered_map<int, vector<string>> &dp) {
        if (i == s.size()) return {""};
        if (dp.find(i) != dp.end()) return dp[i];

        string word;
        vector<string> ans;
        for (int j = i; j < s.size(); j++) {
            word.push_back(s[j]);
            if (dict.find(word) == dict.end()) continue;

            auto end = solveUsingRecursion(s, dict, j + 1, dp);
            for (auto &endpart : end) {
                string validEnd;
                if (!endpart.empty()) validEnd = " " + endpart;
                ans.push_back(word + validEnd);
            }
        }
        dp[i] = ans;
        return ans;
    }

    // Bottom-up dynamic programming
    vector<string> solveUsingTabulation(string s, unordered_set<string> &wordDict) {
        vector<vector<string>> dp(s.size() + 1);
        dp[0] = {""}; // Initialize the first entry as an empty string

        for (int i = 1; i <= s.size(); i++) {
            string word;
            for (int j = i - 1; j >= 0; j--) {
                word = s[j] + word;
                if (wordDict.find(word) != wordDict.end()) {
                    for (const string &sentence : dp[j]) {
                        dp[i].push_back(sentence + (sentence.empty() ? "" : " ") + word);
                    }
                }
            }
        }

        return dp[s.size()];
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, bool> dict;
        for (auto &word : wordDict)
            dict[word] = true;

        // Top-down dynamic programming
        unordered_map<int, vector<string>> dp;
        vector<string> resultRecursion = solveUsingRecursion(s, dict, 0, dp);

        // Bottom-up dynamic programming
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> resultTabulation = solveUsingTabulation(s, wordSet);

        return resultRecursion;
    }
};

int main() {
    Solution solution;

    // Example 1:
    string s1 = "catsanddog";
    vector<string> wordDict1 = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result1 = solution.wordBreak(s1, wordDict1);
    cout << "Example 1: ";
    for (const auto &sentence : result1) {
        cout << sentence << ", ";
    }
    cout << endl;

    // Example 2:
    string s2 = "pineapplepenapple";
    vector<string> wordDict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> result2 = solution.wordBreak(s2, wordDict2);
    cout << "Example 2: ";
    for (const auto &sentence : result2) {
        cout << sentence << ", ";
    }
    cout << endl;

    // Example 3:
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> result3 = solution.wordBreak(s3, wordDict3);
    cout << "Example 3: ";
    for (const auto &sentence : result3) {
        cout << sentence << ", ";
    }
    cout << endl;

    return 0;
}
// class Solution {
// public:
//     vector<string>solveUsingRecursion(string s,unordered_map<string,bool>&dict,int i){
//         //Base Case :
//         if(i == s.size()) return {""}; //return empty string when the whole s is traversed
//         //Check if a string is valid and create a sentence of valid words :
//         string word;
//         vector<string>ans; //ans sentence
//         for(int j = i;j < s.size();j++){
//             word.push_back(s[j]);
//             if(dict.find(word) == dict.end()) continue;
//             //found valid word :
//             auto end = solveUsingRecursion(s,dict,j+1);
//             for(auto endpart: end){
//                 string validEnd;
//                 if(endpart.size() > 0) validEnd =  " " + endpart; //if endpart is valid(not empty)
//                 ans.push_back(word + validEnd);
//             }
//         }
//         return ans;
//     }
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_map<string,bool> dict;
//         for(auto word : wordDict)
//             dict[word] = 1; //marking a word as a valid word
//         return solveUsingRecursion(s,dict,0);
//     }
// };