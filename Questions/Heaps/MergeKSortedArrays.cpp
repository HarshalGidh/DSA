#include <iostream>
#include<queue>
#include<vector>
using namespace std;
class Info{
  public:
    int data;
    int row;
    int col;
    Info(int val,int x_axis,int y_axis): data(val),row(x_axis),col(y_axis){};
};
class compare{
  public:
    bool operator()(Info* a,Info* b){
      return a->data > b->data;
    } 
};
void mergeKSortedArrays(int arr[][4],int n,int k,vector<int>&ans){
  priority_queue<Info*,vector<Info*>,compare>pq;
  //first Process and push the first elements into the heap
  for(int i = 0;i < k;i++){
    int element = arr[i][0]; //0th col means first elements of arrays
    Info* temp = new Info(element,i,0);
    pq.push(temp);
  }
  //push it in ans and get next element
  while(!pq.empty()){
    Info* top = pq.top();pq.pop();
    int topdata = top->data;
    int toprow = top->row;
    int topcol = top->col;
    ans.push_back(topdata);
    //check if theres next element in array :
    if(topcol + 1 < n){
        Info* newInfo = new Info(arr[toprow][topcol + 1],toprow,topcol + 1);
        pq.push(newInfo);
    }
  }
}
int main() {
  int arr[3][4] = {
                    {1,4,8,11},
                    {2,3,6,10},
                    {5,7,12,14}
  };
  int n = 4;
  int k = 3;
  vector<int> ans;
  mergeKSortedArrays(arr,n,k,ans);
  cout << "printing Ans array: " << endl;
  for(int i=0; i<ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}