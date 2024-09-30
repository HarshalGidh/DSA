#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	float a,b,c,d,root1,root2;
	cout<<"Enter coefficients of a,b,c:";
	cin>>a>>b>>c;
	d=(b*b)-(4*a*c);
	if(d>0)
	{
		cout<<"\nTwo real and distinct roots ";
		root1=(-b+sqrt(d))/(2*a);
		root2=(-b-sqrt(d))/(2*a);
		cout<<"\nRoots are "<<root1<<"and "<<root2;
	}
	else if(d==0)
	{
		cout<<"\nTwo real and equal roots";
		root1=-b/(2*a);
		root2=root1;
		cout<<"\nRoots are "<<root1<<"and "<<root2;
	}
	else
		cout<<"\nRoots are Imaginary";
		return 0;
}
