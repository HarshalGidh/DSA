#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);

        for(int index = 0; index<n; index++){
            int new_index =  (index + k)%n ;
            ans[new_index] = nums[index] ;
        }
        //We didnt had to return anything so we assign ans to nums
        nums = ans;
    }
};


int main() {
  cout << "Hello world!" << endl;
  return 0;
}