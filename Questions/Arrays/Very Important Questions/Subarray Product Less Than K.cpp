#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        if (k == 0)
            return 0;
        int n = nums.size(), product = 1, cnt {};
        int l = 0, r = 0;
        while(r < n)
        {
            product *= nums[r++];
            while(l < r && product >= k)
                product /= nums[l++];
            
            cnt += (r - l);
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    cout << "Example 1 Output: " << sol.numSubarrayProductLessThanK(nums1, k1) << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    cout << "Example 2 Output: " << sol.numSubarrayProductLessThanK(nums2, k2) << endl;

    return 0;
}
