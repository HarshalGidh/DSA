#include <iostream>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Line A : arr[i] < arr[i+1]
        // Line B : arr[i] > arr[i+1]
        //Peak Element : arr[i-1] < arr[i] > arr[i+1] so it is also on line B
        int n = arr.size();
        int start = 0;
        int end  = n-1;
        int mid = start + (end-start)/2 ;

        while(start<end){ 
            //Start < End as end = mid not mid -1 to avoid infinite loop
            if(arr[mid] < arr[mid+1]){  //you are on line A go right
                start = mid+1;
            }
            else{ //(arr[mid] > arr[mid+1])//yo are on line B or on Peak element
                end = mid ; //gpoing to left but coming to the mid as peak is
     // on line B and we cant miss it by doing end= mid-1,therefore end = mid
            }
            mid = start + (end-start)/2;
        }
        return start;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}