#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>

using namespace std;

class Solution {
public:
    // Using Binary Search :
    int solveUsingBS(vector<int>& nums, vector<int>& lis) {
        vector<int> ans;
        // insert 1 in lis or lds as the first element will be of 1 mount size:
        lis.push_back(1);
        // Base Case analysed and filled arr with 0th element :
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
                // if a greater element then store the current size of the ans which is LIS
                lis.push_back(ans.size());
            } else {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                lis.push_back(index + 1); // if 0th then 1 will be LIS
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis, lds;
        solveUsingBS(nums, lis);
        // reverse the nums arr and find LIS that will be LDS :
        reverse(nums.begin(), nums.end());
        solveUsingBS(nums, lds);
        int mountSize = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (lis[i] == 1 || lds[nums.size() - i - 1] == 1)
                continue; // ignore the LIS or LDS == 1 as the mount size will be 1
            mountSize = max(mountSize, lis[i] + lds[nums.size() - i - 1] - 1); // -1 as the ith ele will be included 2x
        }
        int minRem = nums.size() - mountSize;
        return minRem;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 3, 1};
    int result1 = sol.minimumMountainRemovals(nums1);
    cout << "Output 1: " << result1 << endl;

    // Example 2
    vector<int> nums2 = {2, 1, 1, 5, 6, 2, 3, 1};
    int result2 = sol.minimumMountainRemovals(nums2);
    cout << "Output 2: " << result2 << endl;

    return 0;
}
