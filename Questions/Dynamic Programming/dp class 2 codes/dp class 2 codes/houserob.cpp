#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int index) {
        //base case
        if(index >= nums.size()) {
            return 0;
        }

        //recursive relation
        int include = nums[index] + solveUsingRecursion(nums, index+2);
        int exclude = 0 + solveUsingRecursion(nums, index+1);
        int ans = max(include, exclude);
        return ans;
    }
    //memo
    int solveUsingMem(vector<int>& nums, int index, vector<int>& dp) {
        //base case
        if(index >= nums.size()) {
            return 0;
        }
        //ans already exists
        if(dp[index] != -1) {
            return dp[index];
        }

        //recursive relation
        int include = nums[index] + solveUsingMem(nums, index+2, dp);
        int exclude = 0 + solveUsingMem(nums, index+1, dp);
        dp[index] = max(include, exclude);
        return dp[index];
    }
    //tabulation
    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        //step1
        vector<int> dp(n, -1);
        //step2
        dp[n-1] = nums[n-1];
        for(int index = n-2; index>=0; index--) {
            int tempAns = 0;
            if(index + 2 < n) {
                tempAns = dp[index+2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index+1];
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }

     int solveUsingTabulationSO(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n-1];
        int next = 0;
        int curr;

        for(int index = n-2; index>=0; index--) {
            int tempAns = 0;
            if(index + 2 < n) {
                tempAns = next;
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + prev;
            curr = max(include, exclude);

            //bhul jata hu
            next = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int index = 0;
        //int ans  = solveUsingRecursion(nums, index);
        //return ans;
        int n = nums.size();
        // vector<int> dp(n, -1);
        // int ans  = solveUsingMem(nums, index, dp);
        // return ans;
        int ans = solveUsingTabulationSO(nums);
        return ans;
    }
};
int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 1};
    int result1 = sol.rob(nums1);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    int result2 = sol.rob(nums2);
    cout << "Example 2: " << result2 << endl;

    return 0;
}

// class Solution {
// public:
//     int solve(vector<int>& nums , int size ,int index){
//         //Base Case
//         if(index >= size){
//             return 0;
//         }
//         //checking 1 case
//         //ghar chori ki 
//         int option1 = nums[index] + solve(nums,size,index + 2);//curr house pe chori ki
//         //index + 2 as next house cant be robbed
//         //ghar chori nahi ki
//         int option2 = 0+ solve(nums,size,index + 1); //chori nahi ki so 0 + solve
//         //index + 1 as next house can be robbed
//         //taking max of both 
//         int finalAns = max(option1 , option2) ;
//         return finalAns;
//     }
//     //using Top-Down Approach :
//     int solveUsingMemo(vector<int>& nums , int size ,int index, vector<int>&dp){
//         //Base Case :
//         if(index >= size) return 0 ;
//         //if ans stored then return ans :
//         if(dp[index] != -1) return dp[index];
//         //checking max ans between including a house and excluding house :
//         int inc = nums[index] + solveUsingMemo(nums,size,index + 2,dp);
//         int exc = 0 + solveUsingMemo(nums,size,index + 1,dp);
//         dp[index] = max(inc,exc);
//         return dp[index];
//     }
//     //using Bottom-up approach:
//     int solveUsingTabulation(vector<int>& nums , int&size ,int&index){
//         //create dp array :
//         vector<int>dp(size+1,0);
//         //Analysing the Base Condition and Filling the Dp with some elements :
//         dp[size - 1] = nums[size - 1];
//         for(int i = size - 2;i>=0;i--){
//             int inc = nums[i] + dp[i + 2]; 
//             int exc = 0 + dp[i + 1];
//             dp[i] = max(inc,exc);
//         }
//         return dp[0];
//     }
//     //using space optimization :
//     int solveUsingTabulationSO(vector<int>& nums , int&size ,int&index){
//         //Analysing the Base Condition and Filling the Dp with some elements :
//         int next = 0;
//         int prev = nums[size - 1];
//         int curr;
//         for(int i = size - 2; i>=0; i--){
//             int inc = nums[i] + next; 
//             int exc = 0 + prev;
//             curr = max(inc,exc);
//             //shifting the pointers
//             next = prev;
//             prev = curr;
//         }
//         return prev ; //returning prev as for 0 size curr wont exist
//     }
//     int rob(vector<int>& nums) {
//         int size = nums.size();
//         int index = 0; //start index
//         //int ans = solve(nums,size,index) ; //Function Call
//         //create dp array :
//         //vector<int>dp(size+1,-1);
//         //int ans = solveUsingMemo(nums,size,index,dp);

//         //int ans  = solveUsingTabulation(nums,size,index);

//         int ans  = solveUsingTabulationSO(nums,size,index);
//         return ans ;
//     }
// };
