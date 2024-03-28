#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Swapping and Sorting
        for(int i = 0; i < n; i++) {
            int index = nums[i];

            // Check if index is in the range of 1 to n
            // Check if index != i + 1; skip if at index i correct element is present.
            // Check if nums[index - 1] != index which means it is in the correct position

            while(index >= 1 && index <= n && index != i + 1 && nums[index - 1] != index) {
                swap(nums[index - 1], nums[i]);
                index = nums[i];
            } 
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] == i + 1) continue; // it is at the correct index
            return i + 1; // found the first missing integer
        }
        return n + 1; // all elements from 1 to n are present
    }
};

int main() {
    // Test cases
    vector<int> nums1 = {1, 2, 0};
    vector<int> nums2 = {3, 4, -1, 1};
    vector<int> nums3 = {7, 8, 9, 11, 12};

    // Create an instance of the Solution class
    Solution sol;

    // Find the first missing positive integer for each test case
    int result1 = sol.firstMissingPositive(nums1);
    int result2 = sol.firstMissingPositive(nums2);
    int result3 = sol.firstMissingPositive(nums3);

    // Output the results
    cout << "Result for nums1: " << result1 << endl;
    cout << "Result for nums2: " << result2 << endl;
    cout << "Result for nums3: " << result3 << endl;

    return 0;
}
