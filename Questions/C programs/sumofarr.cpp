#include<iostream>
using namespace std;

int main()
{
    int arr[100]={1,2,3},size,sum=0;
    cin>>size;
    cout<<"Enter values of array"<<endl;
    for(int i=0;i<size;i++){
        sum=sum + arr[i];
    }
    //ans=sumofarr(arr,size);
    cout<<"The sum of array is :"<<sum;
    return 0;
}