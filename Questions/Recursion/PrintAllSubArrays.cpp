#include <iostream>
#include<vector>
using namespace std;

void PrintSubArraysUtils(vector<int>& nums,int start,int end){
  //Base Case
  if(end >= nums.size()){
    return ;
  }
  //Ek case Processing 
  for(int i = start ; i <= end ;i++){
    cout<<nums[i]<<" ";
  }
  cout<<endl;
  //Baki Recursion Bhaiya sambhal lega Recursion CALL
  PrintSubArraysUtils(nums,start,end+1);
}
void printSubArrays(vector<int>& nums){
  for(int start = 0; start < nums.size();start++){
    int end = start ;
    PrintSubArraysUtils(nums,start,end);
  }
}
int main() {
  vector<int>nums{1,2,3,4,5} ;
  printSubArrays(nums) ;
  return 0;
}