#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int target,int i){
        //Base Case :
        //if i is at end and target is 0 we get a way so 1 else 0
        if(i == nums.size()) return target == 0? 1 : 0;
        //explore all options :
        int plus = solve(nums,target -nums[i],i+1);//target -(+nums[i])= t - n
        int minus = solve(nums,target +nums[i],i+1);//target +(+nums[i])= t + n
        return plus + minus ; //returns all ways through both ways 
    }
    int solveTD(vector<int>& nums, int target,int i,map<pair<int,int>,int>&dp){

        if(i == nums.size()) return target == 0? 1 : 0;
        if(dp.find({i,target}) != dp.end()) return dp[{i,target}] ;
        int plus = solveTD(nums,target -nums[i],i+1,dp);
        int minus = solveTD(nums,target +nums[i],i+1,dp);
        return dp[{i,target}] = plus + minus ; 
    }
    int solveBU(vector<int>& nums, int target){
        //create dp map :
        map<pair<int,int>,int>dp;
        //initialising Base Case :
        dp[{nums.size(),0}] = 1;//starting from end we initialize as 1 
        int total = 0;
        for(auto num :nums){
            total += num ;
        }
        //iterating all ways :
        for(int i = nums.size() - 1;i >=0;i--){
            for(int sum = -total; sum <= total ;sum++){
                int plus =  dp.find({i+1,sum-nums[i]}) != dp.end() ? dp[{i+1,sum -nums[i]}] : 0;
                int minus = dp.find({i+1,sum+nums[i]}) != dp.end() ? dp[{i+1,sum +nums[i]}] : 0 ;
                dp[{i,sum}] = plus + minus ; 
            }
        }
        return dp[{0,target}] ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // return solve(nums,target,0) ;
        //create dp map :
        // map<pair<int,int>,int>dp;
        // return solveTD(nums,target,0,dp) ;
        return solveBU(nums,target) ;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "Example 1 Output: " << sol.findTargetSumWays(nums1, target1) << endl;

    vector<int> nums2 = {1};
    int target2 = 1;
    cout << "Example 2 Output: " << sol.findTargetSumWays(nums2, target2) << endl;

    return 0;
}
