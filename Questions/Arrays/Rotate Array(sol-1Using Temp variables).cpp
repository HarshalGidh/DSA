#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within bounds

        if (k == 0) {
            return; // No need to rotate if k is zero
        }

        vector<int> temp(nums.begin() + (n - k), nums.end()); // Create a temporary vector for rotated elements

        // Move the original elements to make space for rotated elements
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }

        // Copy rotated elements back into the original vector
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};

int main() {
  cout << "Hello world!" << endl;
  return 0;
}