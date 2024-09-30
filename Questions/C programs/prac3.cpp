//program
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,a=0,b=1,c=a+b;
	cout<<"enter a limit of fibonacci series:";
	cin>>n;
  if (n==0)
    cout<<"\nInvalid limit !!";
else if(n==1)
    cout<<"\n"<<a;
else
{
    cout<<"  "<<a<<"  "<<b<<"  ";
    while(c<=n)
    {
    	cout<<c<<" ";
    	a=b;
    	b=c;
    	c=a+b;
	}
  }
	return 0;
}

