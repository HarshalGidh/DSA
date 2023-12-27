#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0;
        int neg = 1;
        for(int i =0;i<n; i++){
            if(nums[i]<0){
                ans[neg] =  nums[i];
                neg+=2;
            }
            else{
                ans[pos] = nums[i];
                pos+=2;
            }
        }
        return ans;

    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}