#include <iostream>
using namespace std;
int BinarySearchRecursion(int *arr,int s,int e,int target){
  int mid = s+(e-s)/2;
  //Base Case
  if(s > e){
    return -1; //Element Not Found
  }
  if(arr[mid] == target){
    //Element Found
    return mid;
  }
  if(arr[mid] < target){
    //go right s = mid + 1;
    return BinarySearchRecursion(arr,mid+1,e,target);
  }
  else{
    //go left e =mid-1;
    return BinarySearchRecursion(arr,s,mid-1,target);
  }
  
}
int main() {
  int arr[] = {10,20,30,40,50,60,70};
  int size = 7;
  int start = 0;
  int end = 6;
  int target= 40 ;
  //int index = 1; //Assuming 0th Index sorted and then comparing with 1st index
  int indexFound = BinarySearchRecursion(arr,start,end,target);
  if(indexFound != -1){//element found
    cout<<"Element Found at :"<<indexFound ;
  }
  else{
    cout<<"Element Not Found";
  }
  return 0;
}