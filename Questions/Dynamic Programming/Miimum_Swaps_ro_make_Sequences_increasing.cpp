#include <iostream>
#include <vector>
#include <algorithm> // for swap
#include <climits> // for INT_MAX

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int p1, int p2){
        //Base Case :
        if(i == nums1.size()) return 0;

        int swap = INT_MAX,noswap = INT_MAX;
        //Swap Cond :
        if(p1 < nums2[i] && p2 < nums1[i])
            swap = 1 + solve(nums1,nums2,i+1,nums2[i],nums1[i]);
        //No Swap Cond :
        if(p1 < nums1[i] && p2 < nums2[i])
            noswap = solve(nums1,nums2,i+1,nums1[i],nums2[i]);
        return min(swap,noswap);
    }
    int solveTD(vector<int>& nums1,vector<int>& nums2,int i,int p1,int p2,vector<vector<int>>&dp,int isSwap){
        //Base Case :
        if(i == nums1.size()) return 0;
        if(dp[i][isSwap] != -1) return dp[i][isSwap] ;
        int swap = INT_MAX,noswap = INT_MAX;
        //Swap Cond :
        if(p1 < nums2[i] && p2 < nums1[i])
            swap = 1 + solveTD(nums1,nums2,i+1,nums2[i],nums1[i],dp,1);
        //No Swap Cond :
        if(p1 < nums1[i] && p2 < nums2[i])
            noswap = solveTD(nums1,nums2,i+1,nums1[i],nums2[i],dp,0);
        return dp[i][isSwap] = min(swap,noswap);
    }
    int solveBU(vector<int>& nums1,vector<int>& nums2){
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
        for(int i = nums1.size()-1;i >= 1;i--){
            for(int j = 1;j >= 0;j--){
                int prev1 = nums1[i-1];
                int prev2 = nums2[i-1];
                if(j){//swapping 
                    swap(prev1,prev2);
                }
                int swap = INT_MAX,noswap = INT_MAX;
                //Swap Cond :
                if(prev1 < nums2[i] && prev2 < nums1[i])
                    swap = 1 + dp[i+1][1];
                //No Swap Cond :
                if(prev1 < nums1[i] && prev2 < nums2[i])
                    noswap = dp[i+1][0];
                dp[i][j] = min(swap,noswap); //returning max substr
            }
        }
        return dp[1][0] ;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // return solve(nums1,nums2,0,-1,-1);

        //Recursion varies on 2 condition : swap or nowswap
        //Also p1 and p2 are not dynamically changing as for an i p1,p2 is always behind them
        // vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        // return solveTD(nums1,nums2,0,-1,-1,dp,0);

        //insert -1 in beginning of nums1 and 2, so that -1 can be compared with oth index of nums1 ,2
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solveBU(nums1,nums2);
    }
};

int main() {
    Solution sol;
    vector<int> nums1_1 = {1, 3, 5, 4};
    vector<int> nums2_1 = {1, 2, 3, 7};
    cout << "Example 1 Output: " << sol.minSwap(nums1_1, nums2_1) << endl;

    vector<int> nums1_2 = {0, 3, 5, 8, 9};
    vector<int> nums2_2 = {2, 1, 4, 6, 9};
    cout << "Example 2 Output: " << sol.minSwap(nums1_2, nums2_2) << endl;

    return 0;
}
