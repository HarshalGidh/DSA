#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Node{
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val), left(0),right(0){};
};
void checkValidBST(vector<int>&preorder,int lowerBound,int upperBound,int &i){
  if(i >= preorder.size()) return;

  if(preorder[i] >= lowerBound && preorder[i] <= upperBound){
    int rootData = preorder[i++];
    checkValidBST(preorder,lowerBound,rootData,i);
    checkValidBST(preorder,rootData,upperBound,i);
  }
}
bool isValidBST(vector<int>&preorder){
  int lowerBound = INT_MIN;
  int upperBound = INT_MAX;
  int i = 0;
  checkValidBST(preorder,lowerBound,upperBound,i);
  return i == preorder.size();
}
int main() {
  vector<int>preorder = {10,8,7,9,20,15,21};
  cout<<"Checking if valid "<<endl;
  bool validBST = isValidBST(preorder);
  if(validBST){
    cout<<"Is valid BST "<<endl;
  }
  else{
    cout<<"Invalid BST"<<endl;
  }
  return 0;
}