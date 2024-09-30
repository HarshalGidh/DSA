#include<iostream>
using namespace std;
int main()
{
	int n=0,i,j;
	cout<<"(The number entered should be odd)\n";
	cout<<"Enter the number of rows:";
	cin>>n;
	int m=(n+1)/2;
	if(n%2==0&&n!=1)
	{
		cout<<"The no. you enetered is even\n";
		return 0;
	}
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<(m-1);j++)
		{
			cout<<" ";
		}
		for(j=0;j<3+i;j++)
		{
			cout<<"* ";
		}
		cout<<"\n";
	}
	for(i=m-1;i>=0;i--)
	{
		for(j=(m-i);j>0;j--)
		{
			cout<<" ";
		}
		for(j=(3+i);j>0;j--)
		{
			cout<<"* ";
		}
		cout<<"\n";
	}
	return 0;
}
