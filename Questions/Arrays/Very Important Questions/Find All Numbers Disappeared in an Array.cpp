#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int index = abs(nums[i]);
            if(nums[index - 1] > 0) nums[index - 1] *= -1;
        }
        // Push missing elements into the vector
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) ans.push_back(i + 1);
        }
        return ans;
    }
};

int main() {
    // Test cases
    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> nums2 = {1, 1};

    // Create an instance of the Solution class
    Solution sol;

    // Find the disappeared numbers for each test case
    vector<int> result1 = sol.findDisappearedNumbers(nums1);
    vector<int> result2 = sol.findDisappearedNumbers(nums2);

    // Output the results
    cout << "Result for nums1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result for nums2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
