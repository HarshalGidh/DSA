#include <iostream>
using namespace std;
#include<stack>
#include<queue>
#include<deque>
void printFirstNegativeNumber(int *arr,int n,int k){
    deque<int> dq;

    //process first k elements - first window
    for(int index = 0;index < k ;index++){
        int element = arr[index];//getting element
        if(element < 0){
            dq.push_back(index);
        }
    }
    //process remaining windows - Removal and Addition of elements from the window
    for(int index = k;index<n;index++){
        //previous window answer :
        if(dq.empty()){
            cout<<"0"<<endl; //0 means no negative number in that window(1st window)
        }
        else{
            cout<<arr[dq.front()]<<" ";
        }
        //Removal -removing indexes stored inside deque if its no longer in window
        if(index - dq.front() >= k ){
            dq.pop_front(); //removing front element from dq
        }
        //Addition - adding new index in Deque if element is negative
        if(arr[index] < 0){
            dq.push_back(index); //new negative number's index getting stored
        }
    }
    //last window answer : as we cant print answer for last window inside for loop we do it here
    if(dq.empty()){
        cout<<"0"<<endl; //0 means no negative number in that window(last window)
    }
    else{
        cout<<arr[dq.front()]<<" ";
    }
}
int main() {
  int arr[] = {2,-5,4,-1,-2,0,5};
  int size = 7;
  int k = 3;
  printFirstNegativeNumber(arr,size,k);
  return 0;
}