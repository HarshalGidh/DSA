//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
#include <iostream>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i<n;i++){
            sum = sum + nums[i];
        }
        //Subtracting the actual sum of n numbers with the sum of given nums
        //The difference between the actual sum and given sum will be our 
        //Missing Num
        int ans = n*(n+1)/2 - sum ;
        return ans;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}