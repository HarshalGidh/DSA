//Arranging Negative numbers on one side
#include <iostream>
using namespace std;
void shiftNegative(int arr[],int n)
{
  int index=0;
  int neg=0;
  for(index=0;index<n;index++){
    if(arr[index]<0){
      swap(arr[index], arr[neg]);
      neg++;
    }
  }
}
int main() {
  int arr[]={23,-7,12,-10,-11,40,60};
  int n = 7;    //sizeof(arr);
//Before Arranging
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  shiftNegative(arr,n);
  //Printing Array after arranging
  cout<<"\nPrinting Array after arranging:"<<endl;
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}