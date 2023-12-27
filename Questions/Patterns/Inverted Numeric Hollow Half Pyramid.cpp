#include <iostream>
using namespace std;

int main() {
  int n;
  int counter= 0;
  cin>>n;
  for(int row=0;row<n;row++){
    for(int col=0;col<n-row;col++){
      if(col==0 || row==0 || col==n-row-1){
        cout<<col+counter+1<<" ";
      }
      else{
        cout<<"  ";
      }
    }
    counter++;
    cout<< endl;
  }
  return 0;
}