#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int solveUsingRecursion(vector<vector<int>>& env, int prev, int i) {
        // Base Case:
        if (i == env.size()) return 0;
        int include = INT_MIN;
        if (prev == -1 || (env[prev][0] < env[i][0] && env[prev][1] < env[i][1])) {
            include = 1 + solveUsingRecursion(env, i, i + 1);
        }
        int exclude = 0 + solveUsingRecursion(env, prev, i + 1);
        return max(include, exclude);
    }

    int solveUsingMem(vector<vector<int>>& env, int prev, int i, vector<vector<int>>& dp) {
        // Base Case:
        if (i == env.size()) return 0;
        if (dp[prev + 1][i] != -1) return dp[prev + 1][i];
        int include = INT_MIN;
        if (prev == -1 || (env[prev][0] < env[i][0] && env[prev][1] < env[i][1])) {
            include = 1 + solveUsingMem(env, i, i + 1, dp);
        }
        int exclude = 0 + solveUsingMem(env, prev, i + 1, dp);
        return dp[prev + 1][i] = max(include, exclude);
    }

    static bool comparator(vector<int>& a, vector<int>& b) {
        // if width is equal then compare heights
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    // Using Binary Search :
    int solveOptimalSol(vector<vector<int>>& env) {
        // sort the envelopes in width wise asc order :
        // and if wi == wj then sort height in desc order :
        sort(env.begin(), env.end(), comparator);
        vector<int> ans;

        // Apply LIS on the height of the envelopes
        // Base Case analysed and filled arr with the 0th element :
        ans.push_back(env[0][1]);
        for (int i = 1; i < env.size(); i++) {
            if (env[i][1] > ans.back()) {
                ans.push_back(env[i][1]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), env[i][1]) - ans.begin();
                ans[index] = env[i][1];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort the envelopes :
        // sort(envelopes.begin(),envelopes.end()) ;
        // return solveUsingRecursion(envelopes,-1,0);
        // create 2d dp :
        // vector<vector<int> >dp(envelopes.size()+1,vector<int>(envelopes.size()+1,-1));
        // return solveUsingMem(envelopes,-1,0,dp);
        return solveOptimalSol(envelopes);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> envelopes1 = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    int result1 = sol.maxEnvelopes(envelopes1);
    cout << "Output 1: " << result1 << endl;

    // Example 2
    vector<vector<int>> envelopes2 = {{1, 1}, {1, 1}, {1, 1}};
    int result2 = sol.maxEnvelopes(envelopes2);
    cout << "Output 2: " << result2 << endl;

    return 0;
}
