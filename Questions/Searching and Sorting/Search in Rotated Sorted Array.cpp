#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int FindPivotIndex(vector<int>& arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2 ; 

        while(s<=e){
            if(s == e){
                // For a single element array
                return s ; 
            }
            else if(mid - 1 >= 0 && arr[mid] < arr[mid-1]){
                //mid+1<n so that index is within range of n
                //if you are on smallest number and on left is pivot
                return mid -1;
            }
            else if(mid+1 < n && arr[mid] > arr[mid+1]){
                //mid-1>=0 so that mid doesnt goes to a negative index
                //If you are on Max element (Pivot Element)
                return mid;
            }
            else if(arr[s] > arr[mid]){
                //If you are on line B
                e = mid-1;
            }
            else{
                //If you are on Line A
                s = mid +1;
            }
            mid = s + (e-s)/2 ; 
        }
        return -1 ; 
    }
    int BinarySearch(vector<int>& arr,int s ,int e,int target){
        int mid = s + (e-s)/2;
        
        
        while(s<=e){
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] < target){
                
                s = mid +1;
            }
            else{
                e = mid -1;
            }
            mid = s +(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans;
        int pivot_index = FindPivotIndex(nums);
        //Search in A:
        if (target >= nums[0] && target <= nums[pivot_index]){
            ans = BinarySearch(nums,0,pivot_index,target);
        }
        //Search in line B:
        else{
            //(target >= nums[pivot_index +1]  &&  nums[n-1])
            ans = BinarySearch(nums,pivot_index + 1,n-1,target);
        }

        return ans;

    }
};
int main() {
  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  /*
  v.push_back(12);
  v.push_back(14);
  v.push_back(16);
  v.push_back(2);
  v.push_back(4);
  v.push_back(6);
  v.push_back(8);
  v.push_back(10);
  */
  int pivot_index = FindPivotIndex(v);
  cout<<"Pivot Index is : "<<pivot_index<<endl ;
  return 0;
}