#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums,int start ,int end){
        //Base Case :when start and end are on same point 
        if(start == end) return nums[start] ;
        int diffByStart = nums[start] - solve(nums,start+1,end);
        int diffByEnd = nums[end]  - solve(nums,start,end-1);
        return max(diffByStart,diffByEnd);
    }
    int solveTD(vector<int>& nums,int start ,int end,vector<vector<int>>&dp){
        //Base Case :when start and end are on same point 
        if(start == end) return nums[start] ;
        if(dp[start][end] != -1) return dp[start][end];
        int diffByStart = nums[start] - solveTD(nums,start+1,end,dp);
        int diffByEnd = nums[end]  - solveTD(nums,start,end-1,dp);
        return dp[start][end] = max(diffByStart,diffByEnd);
    }
    
    int solveBU(vector<int>& nums,vector<vector<int>>&dp){
        //Fill elements using TD Base Case :
        //Fill all Diagonal elements :
        for(int i = 0; i < nums.size();i++){
            dp[i][i] = nums[i];
        }
        int i = nums.size();
        for(int start = nums.size()-1;start >=0;start--){
            for(int end = i;end < nums.size();end++){
                int diffByStart = nums[start] - dp[start+1][end] ;
                int diffByEnd = nums[end]  - dp[start][end-1] ;
                dp[start][end] = max(diffByStart,diffByEnd);
            }
            i--;
            
        }
        print(dp);
        return dp[0][nums.size() - 1] ;
    }
    void print(vector<vector<int>>&dp){
        for(int i = 0;i<dp.size();i++){
            cout<<i<<" : ";
            for(int j = 0;j<dp[0].size();j++){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        // return solve(nums,0,nums.size()-1) >= 0;

        // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return solveTD(nums,0,nums.size()-1,dp) >= 0;

        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,0));
        return solveBU(nums,dp) >= 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums_1 = {1, 5, 2};
    cout << "Example 1 Output: " << sol.predictTheWinner(nums_1) << endl;

    vector<int> nums_2 = {1, 5, 233, 7};
    cout << "Example 2 Output: " << sol.predictTheWinner(nums_2) << endl;

    return 0;
}
