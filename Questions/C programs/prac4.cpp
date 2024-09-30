#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i,num,rem,rev=0;
	cout<<"Enter a number:";
	cin>>num;
	i=num;
	while(i!=0)
	{
		rem=i%10;
		rev=(rev*10)+rem;
		i=i/10;
	}
	cout<<"\nThe Reverse of "<<num<<" is :"<<rev;
	return 0;
}
