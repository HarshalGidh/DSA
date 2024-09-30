#include<iostream>
using namespace as std;
long long int sqrtInteger(int n){
    int s=0;
    int e=n;
    long long int mid = s + (e - s) / 2;
    long long int ans=-1;
    while(s<=e){
        long long int square=mid*mid;
        if(square==n){
            return mid;
        }
        else if(square<n){
            ans=mid;
            s=mid +1;
        }
        else{
            e=mid-1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
double precision(int n,int precision,int tempSol){
    double factor=1;
    ans=tempSol;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j = ans; j*j < n; j=j+factor)
        {
            ans=j;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter a number :"<<endl;
    cin>>n;
    int tempSol= sqrtInteger(n);
    cout<<"Answer is :"<<precision(n,3,tempSol)<<endl;

    return 0;
}