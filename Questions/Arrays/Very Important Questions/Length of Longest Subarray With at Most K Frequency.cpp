#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
    }
    
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int l = 0, r = 0, cnt {};
        while(r < n) {
            int cur = nums[r++];
            mp[cur]++;
            while(l < r && mp[cur] > k) {
                mp[nums[l++]]--;
            }
            cnt = max(cnt, r - l);
        }
        return cnt;
    }
};

int main() {
    // Test cases
    vector<int> nums1 = {1, 2, 3, 1, 2, 3, 1, 2};
    int k1 = 2;
    Solution sol1;
    cout << "Output 1: " << sol1.maxSubarrayLength(nums1, k1) << endl;  // Expected output: 6
    
    vector<int> nums2 = {1, 2, 1, 2, 1, 2, 1, 2};
    int k2 = 1;
    Solution sol2;
    cout << "Output 2: " << sol2.maxSubarrayLength(nums2, k2) << endl;  // Expected output: 2
    
    vector<int> nums3 = {5, 5, 5, 5, 5, 5, 5};
    int k3 = 4;
    Solution sol3;
    cout << "Output 3: " << sol3.maxSubarrayLength(nums3, k3) << endl;  // Expected output: 4
    
    return 0;
}

