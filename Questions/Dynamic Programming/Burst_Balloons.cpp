#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int solveUsingRecursion(vector<int>& nums,int s,int e){
        //Base Case :
        if(s > e) return 0; 
        //Traverse all the ballons and burst it smartly :
        int coins = INT_MIN ;
        for(int i = s;i <= e; i++){
            coins = max(coins,
                        nums[s-1]*nums[i]*nums[e+1]
                        + solveUsingRecursion(nums,s,i-1)
                        + solveUsingRecursion(nums,i+1,e) );
        }
        return coins ;
    }
    int solveUsingMem(vector<int>& nums,int s,int e,vector<vector<int> >&dp){
        //Base Case :
        if(s > e) return 0; 
        if(dp[s][e] != -1) return dp[s][e] ;
        //Traverse all the ballons and burst it smartly :
        int coins = INT_MIN ;
        for(int i = s;i <= e; i++){
            coins = max(coins,
                        nums[s-1]*nums[i]*nums[e+1]
                        + solveUsingMem(nums,s,i-1,dp)
                        + solveUsingMem(nums,i+1,e,dp) );
        }
        return dp[s][e] = coins ;
    }
    int solveUsingTabulation(vector<int>& nums){
        // create 2d dp :
       vector<vector<int> > dp(nums.size(),vector<int>(nums.size(),0));
       int n = nums.size() - 2;
       for(int s = n;s >= 1;s--){
           for(int e = s;e <= n ;e++){
               int coins = INT_MIN ;
                for(int i = s;i <= e; i++){
                    coins = max(coins,
                                nums[s-1]*nums[i]*nums[e+1]
                                + dp[s][i-1]
                                + dp[i+1][e] );
                }
                dp[s][e] = coins ;
           }
       }
       printdp(dp);
       return dp[1][n] ;
    }
   void printdp(vector<vector<int>> &dp) {
    for (int i = 0; i < dp.size(); i++) {
        cout << "row " << i << ": ";
        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
    int maxCoins(vector<int>& nums) {
        //Insert 2 imaginary balloons :
        nums.insert(nums.begin(),1) ;
        nums.insert(nums.end(),1) ;
       // return solveUsingRecursion(nums,1,nums.size() -2);
       //create 2d dp :
    //    vector<vector<int> > dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    //    return solveUsingMem(nums,1,nums.size() -2,dp) ;
        return solveUsingTabulation(nums) ;
        // return solveUsingTabulationSO(nums) ;
    }

};
int main() {
    Solution sol;

    // Example
    vector<int> nums = {3, 1, 5, 8};
    int result = sol.maxCoins(nums);
    cout << "Output: " << result << endl;

    return 0;
}