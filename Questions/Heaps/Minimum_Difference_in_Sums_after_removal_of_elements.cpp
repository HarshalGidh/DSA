#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const int n = nums.size() / 3;

        if (nums.size() < 3 * n) {
            // Handle the case where the input size is less than expected.
            return -1;
        }
        //creatig Max Heap and Min Heap :
        priority_queue<long long> maxHeap;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        //Creating Prefix(first n numbers) and Suffix(last n numbers)
        vector<long long> prefix(nums.size(), -1);
        vector<long long> suffix(nums.size(), -1);
        //push elements in Max Heap and add it to sum:
        long long min_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            min_sum += nums[i];
            maxHeap.push(nums[i]);

            if (maxHeap.size() > n) {
                min_sum -= maxHeap.top(); //subtracting the max element from sum so that we will get min sum
                maxHeap.pop();
            }

            if (maxHeap.size() == n) {
                prefix[i] = min_sum;
            }
        }

        long long max_sum = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            max_sum += nums[i];
            minHeap.push(nums[i]);

            if (minHeap.size() > n) {
                max_sum -= minHeap.top();//subtracting the min element from sum so that we will get max sum
                minHeap.pop();
            }

            if (minHeap.size() == n) {
                suffix[i] = max_sum;
            }
        }
        //calculating minimum difference :
        long long diff = LLONG_MAX;  // initialising by max element to get min diff 
        for (int i = n - 1; i < 2 * n; ++i) { //hence we get a loop for N/2 times
            diff = min(diff, prefix[i] - suffix[i + 1]);
        }

        return diff;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1};
    long long output1 = sol.minimumDifference(nums1);
    cout << "Output 1: " << output1 << endl;

    // Example 2
    vector<int> nums2 = {10, 100};
    long long output2 = sol.minimumDifference(nums2);
    cout << "Output 2: " << output2 << endl;

    // Example 3
    vector<int> nums3 = {10, 60, 20, 30, 30, 30, 60, 40};
    long long output3 = sol.minimumDifference(nums3);
    cout << "Output 3: " << output3 << endl;

    return 0;
}
