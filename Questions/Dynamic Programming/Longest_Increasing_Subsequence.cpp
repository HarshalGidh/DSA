#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr, int prev) {
        // Base Case :
        if (curr >= nums.size()) return 0; // If no num then return 0
        int include = 0, exclude, ans;
        if (prev == -1 || nums[prev] < nums[curr]) {
            include = 1 + solveUsingRecursion(nums, curr + 1, curr); // If included then prev will be at 
            // curr and curr will be 1 step ahead
        }
        // If excluded only curr will go ahead :
        exclude = 0 + solveUsingRecursion(nums, curr + 1, prev);
        ans = max(include, exclude);
        return ans;
    }

    int solveUsingMemo(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
        // Base Case :
        if (curr >= nums.size()) return 0; // If no num then return 0
        // If ans already stored return ans :
        if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

        int include = 0, exclude;
        if (prev == -1 || nums[prev] < nums[curr]) {
            include = 1 + solveUsingMemo(nums, curr + 1, curr, dp); // If included then prev will be at 
            // curr and curr will be 1 step ahead
        }
        // If excluded only curr will go ahead :
        exclude = 0 + solveUsingMemo(nums, curr + 1, prev, dp); // Doing index shifting for prev
        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        // Create dp array :
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // Base Case analyzed and filled dp arr with 0:
        for (int i = n - 1; i >= 0; i--) {
            // Since prev is always behind curr j=i-1 and goes till -1
            for (int j = i - 1; j >= -1; j--) {
                int include = 0, exclude;
                if (j == -1 || nums[j] < nums[i]) {
                    include = 1 + dp[i + 1][i + 1]; // If included then prev will be at 
                    // curr and curr will be 1 step ahead
                    // here prev will also be i+1 as we are starting from -1 so we need to index shift here
                }
                // If excluded only curr will go ahead :
                exclude = 0 + dp[i + 1][j + 1]; // Doing index shifting for prev
                dp[i][j + 1] = max(include, exclude);
            }
        }
        return dp[0][0]; // prev is -1 + 1
    }

    int solveUsingTabulationSO(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextRow(n + 1, 0);
        vector<int> prevRow(n + 1, 0);
        // Base Case analyzed and filled dp arr with 0th element :
        for (int i = n - 1; i >= 0; i--) {
            // Since prev is always behind curr j=i-1 and goes till -1
            for (int j = i - 1; j >= -1; j--) {
                int include = 0, exclude;
                if (j == -1 || nums[j] < nums[i]) {
                    include = 1 + nextRow[i + 1]; // If included then prev will be at 
                    // curr and curr will be 1 step ahead
                    // here prev will also be i+1 as we are starting from -1 so we need to index shift here
                }
                // If excluded only curr will go ahead :
                exclude = 0 + nextRow[j + 1]; // Doing index shifting for prev
                prevRow[j + 1] = max(include, exclude);
            }
            // Shifting L
            nextRow = prevRow;
        }
        return nextRow[0];
    }

    int solveUsingBS(vector<int>& nums) {
        vector<int> ans;

        // Base Case analyzed and filled arr with 0th element :
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0, prev = -1;
        int n = nums.size();
        // int ans = solveUsingRecursion(nums,curr,prev);
        // return ans;

        // Create dp array :
        // vector<vector<int> >dp(n+1,vector<int>(n+1,-1));
        // int ans = solveUsingMemo(nums,curr,prev,dp);

        // int ans = solveUsingTabulation(nums);

        // int ans = solveUsingTabulationSO(nums);
        // return ans;
        return solveUsingBS(nums);
    }
};

int main() {
    Solution solution;
    // Example 1:
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Example 1: " << solution.lengthOfLIS(nums1) << endl;

    // Example 2:
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Example 2: " << solution.lengthOfLIS(nums2) << endl;

    // Example 3:
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Example 3: " << solution.lengthOfLIS(nums3) << endl;

    return 0;
}
