#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    int solve(vector<int>& satisfaction,int i,int time){
        //Base Case :
        if(i == satisfaction.size()) return 0;
        int include = 0, exclude = 0;
        include = time *satisfaction[i] + solve(satisfaction,i+1,time+1);
        exclude = 0 + solve(satisfaction,i+1,time);
        return max(include,exclude) ; 
    }
    int solveTD(vector<int>& satisfaction,int i,int time,vector<vector<int>>&dp){
        //Base Case :
        if(i == satisfaction.size()) return 0;
        if(dp[i][time] != -1) return dp[i][time];
        int include = 0, exclude = 0;
        include = time *satisfaction[i] + solveTD(satisfaction,i+1,time+1,dp);
        exclude = 0 + solveTD(satisfaction,i+1,time,dp);
        return dp[i][time] = max(include,exclude) ; 
    }
    int solveBU(vector<int>& satisfaction){
        vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+2,0));
        for(int i = satisfaction.size()-1;i>=0;i--){
            for(int time = satisfaction.size();time>=1;time--){
                int include = 0, exclude = 0;
                include = time *satisfaction[i] + dp[i+1][time+1];
                exclude = 0 + dp[i+1][time];
                dp[i][time] = max(include,exclude) ;
            }
        }
        return dp[0][1];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction,0,1);

        // vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        // return solveTD(satisfaction,0,1,dp);

        return solveBU(satisfaction);
    }
};

int main() {
    Solution sol;
    vector<int> satisfaction_1 = {-1, -8, 0, 5, -9};
    cout << "Example 1 Output: " << sol.maxSatisfaction(satisfaction_1) << endl;

    vector<int> satisfaction_2 = {4, 3, 2};
    cout << "Example 2 Output: " << sol.maxSatisfaction(satisfaction_2) << endl;

    vector<int> satisfaction_3 = {-1, -4, -5};
    cout << "Example 3 Output: " << sol.maxSatisfaction(satisfaction_3) << endl;

    return 0;
}
