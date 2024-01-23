#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solveUsingRecursion(string &a, string &b, int i, int j) {
        // Base Case:
        if (i == a.length()) { // Word1 got exhausted, so insert elements of b.
            return b.length() - j; // Adding b.length - j operations for insertions.
        }
        if (j == b.length()) { // Word2 got exhausted, so delete elements of a.
            return a.length() - i; // Removing a.length - i operations for insertions.
        }
        int ans;
        // If chars get matched:
        if (a[i] == b[j]) {
            ans = 0 + solveUsingRecursion(a, b, i + 1, j + 1);
        }
        // If chars don't match:
        else { // We have 3 ops: replace, insert, delete.
            int replace = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
            int insert = 1 + solveUsingRecursion(a, b, i + 1, j);
            int remove = 1 + solveUsingRecursion(a, b, i, j + 1);
            ans = min(replace, min(insert, remove));
        }
        return ans;
    }

    int solveUsingMemo(string &a, string &b, int i, int j, vector<vector<int>> &dp) {
        // Base Case:
        if (i == a.length()) { // Word1 got exhausted, so insert elements of b.
            return b.length() - j; // Adding b.length - j operations for insertions.
        }
        if (j == b.length()) { // Word2 got exhausted, so delete elements of a.
            return a.length() - i; // Removing a.length - i operations for insertions.
        }
        if (dp[i][j] != 0) return dp[i][j];
        int ans;
        // If chars get matched:
        if (a[i] == b[j]) {
            ans = 0 + solveUsingMemo(a, b, i + 1, j + 1, dp);
        }
        // If chars don't match:
        else { // We have 3 ops: replace, insert, delete.
            int replace = 1 + solveUsingMemo(a, b, i + 1, j + 1, dp);
            int insert = 1 + solveUsingMemo(a, b, i + 1, j, dp);
            int remove = 1 + solveUsingMemo(a, b, i, j + 1, dp);
            ans = min(replace, min(insert, remove));
        }
        return dp[i][j] = ans;
    }

    int solveUsingTabulation(string &a, string &b) {
        // Create dp array:
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
        // Analysing Base Case and filling the array:
        // If b gets exhausted, we delete ele in a of a.length - row.
        // Filling the last col with the delete ans.
        for (int row = 0; row <= a.length(); row++) {
            dp[row][b.length()] = a.length() - row;
        }
        // If a gets exhausted, we insert ele in a of b.length - col.
        // Filling the last row with the insertion ans.
        for (int col = 0; col <= b.length(); col++) {
            dp[a.length()][col] = b.length() - col;
        }
        // Filling array elements:
        for (int j = b.length() - 1; j >= 0; j--) {
            for (int i = a.length() - 1; i >= 0; i--) {
                int ans;
                // If chars get matched:
                if (a[i] == b[j]) {
                    ans = 0 + dp[i + 1][j + 1];
                }
                // If chars don't match:
                else { // We have 3 ops: replace, insert, delete.
                    int replace = 1 + dp[i + 1][j + 1];
                    int insert = 1 + dp[i + 1][j];
                    int remove = 1 + dp[i][j + 1];
                    ans = min(replace, min(insert, remove));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabulationSO(string &a, string &b) {
        // Creating two col arrays of the same size:
        vector<int> next(a.length() + 1, 0); // Initializing with the col length + 1
        vector<int> curr(a.length() + 1, 0);
        // Filling the last col (initially next) with the delete values:
        // This is done when b.length() < a.length(), so we do deletion of a to match b.
        for (int row = 0; row <= a.length(); row++) {
            next[row] = a.length() - row;
        }
        // Filling the rest of the matrix:
        for (int j = b.length() - 1; j >= 0; j--) {
            // Filling the last row with insert values:
            // This is done when a.length() < b.length(), so we insert b.length()-j to match a with b.
            curr[a.length()] = b.length() - j;
            for (int i = a.length() - 1; i >= 0; i--) {
                int ans;
                // If matched:
                if (a[i] == b[j]) {
                    ans = 0 + next[i + 1]; // Get ans from the next col next row.
                } else {
                    // Perform any of the 3 operations:
                    int replace = 1 + next[i + 1];
                    int insert = 1 + next[i];
                    int remove = 1 + curr[i + 1];
                    ans = min(replace, min(insert, remove));
                }
                curr[i] = ans;
            }
            // Shifting
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        // int i = 0, j = 0;
        // return solveUsingRecursion(word1, word2, i, j);
        // Create dp array:
        // vector<vector<int> >dp(word1.length(), vector<int>(word2.length(), 0));
        // return solveUsingMemo(word1, word2, i, j, dp);
        // return solveUsingTabulation(word1, word2);
        return solveUsingTabulationSO(word1, word2);
    }
};
  void printDP(vector<vector<int> >&dp){
        for(int i = 0;i < dp.size();i++){
            cout<<i<<endl;
            for(int j =0;j < dp[0].size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
int main() {
    Solution solution;

    // Example 1:
    string word1 = "horse";
    string word2 = "ros";
    cout << "Example 1: " << solution.minDistance(word1, word2) << endl;

    // Example 2:
    string word3 = "intention";
    string word4 = "execution";
    cout << "Example 2: " << solution.minDistance(word3, word4) << endl;

    return 0;
}
