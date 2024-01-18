#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int size, int index, vector<int>& dp) {
        // Base Case
        if (index >= size) {
            return 0;
        }
        // If answer is already stored then return it
        if (dp[index] != 0) {
            return dp[index];
        }
        // Checking maximum answer between including a house and excluding house
        int inc = nums[index] + solve(nums, size, index + 2, dp);
        int exc = 0 + solve(nums, size, index + 1, dp);
        dp[index] = max(inc, exc);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, 0);

        // Rob houses excluding the last one
        int result1 = solve(nums, n - 1, 0, dp);
        // Rob houses excluding the first one
        int result2 = solve(nums, n, 1, dp);

        // Return the maximum result
        return max(result1, result2);
    }
};

int main() {
    // Example 1
    vector<int> nums1 = {2, 3, 2};
    Solution solution1;
    int result1 = solution1.rob(nums1);
    cout << "Example 1: " << result1 << endl;  // Output: 3

    // Example 2
    vector<int> nums2 = {1, 2, 3, 1};
    Solution solution2;
    int result2 = solution2.rob(nums2);
    cout << "Example 2: " << result2 << endl;  // Output: 4

    // Example 3
    vector<int> nums3 = {1, 2, 3};
    Solution solution3;
    int result3 = solution3.rob(nums3);
    cout << "Example 3: " << result3 << endl;  // Output: 3

    return 0;
}
