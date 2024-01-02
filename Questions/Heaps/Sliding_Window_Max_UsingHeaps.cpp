#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        //create Max Heap : (pair<value,index>)
        priority_queue<pair<int, int>> pq;
        //push k elements in Max Heap :
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first); //push top(max) of 1st k elemnts in ans
        //Push rest of window elemnts :
        for (int i = k; i < nums.size(); i++) {
            pq.push({nums[i], i});
            //check if top of max Heap is out of window range, if yes then remove them from heap
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> output1 = sol.maxSlidingWindow(nums1, k1);
    cout << "Output 1: [";
    for (int i = 0; i < output1.size(); i++) {
        cout << output1[i];
        if (i != output1.size() - 1)
            cout << ", ";
    }
    cout << "]\n";

    // Example 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> output2 = sol.maxSlidingWindow(nums2, k2);
    cout << "Output 2: [";
    for (int i = 0; i < output2.size(); i++) {
        cout << output2[i];
        if (i != output2.size() - 1)
            cout << ", ";
    }
    cout << "]\n";

    return 0;
}
