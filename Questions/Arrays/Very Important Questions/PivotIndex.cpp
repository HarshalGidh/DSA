#include <iostream>
#include<vector>
using namespace std;
int FindPivotIndex(vector<int>& arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2 ; 
        // Line B always has elements < Line A elements
        while(s<=e){
            if(s == e){
                // For a single element array
                return s ; 
            }
            else if(arr[mid] < arr[mid-1]){
                //if you are on smallest number and on left is pivot
                return mid -1;
            }
            else if(arr[mid] > arr[mid+1]){
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