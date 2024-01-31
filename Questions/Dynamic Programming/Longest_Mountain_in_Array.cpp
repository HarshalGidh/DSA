#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int result = 0;
        for (int peak = 1; peak < n - 1; ) {
            if (arr[peak - 1] < arr[peak] && arr[peak] > arr[peak + 1]) {
                int left = peak - 1;
                while (left > 0 && arr[left - 1] < arr[left]) {
                    --left;
                }
                int right = peak + 1;
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    ++right;
                }
                result = max(result, right - left + 1);
                peak = right + 1;
            } else {
                ++peak;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {2, 1, 4, 7, 3, 2, 5};
    int result1 = sol.longestMountain(arr1);
    cout << "Output 1: " << result1 << endl;

    // Example 2
    vector<int> arr2 = {2, 2, 2};
    int result2 = sol.longestMountain(arr2);
    cout << "Output 2: " << result2 << endl;

    return 0;
}
