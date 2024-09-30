#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int x,y,result;
	char op;
	do
   {
		cout<<"\nPlease enter the operand of the problem you would like to solve:";
		cout<<"\n+ for addition";
		cout<<"\n- for subtraction";
		cout<<"\n* for multiplication";
		cout<<"\n/ for division";
		cout<<"\nEnter Q to quit";
		cout<<"\nEnter your choice: ";
		cin>> op;
		cout<<"\nPlease enter the two numbers: ";
		cin>> x >> y;
		switch (op)
	   {
			case '+':
					result = x+y;
					cout<<"\nThe answer is: " << result;
					break;

			case '-':
					result = x-y;
					cout<<"\nThe answer is: " << result;
					break;

			case '*':
					result = x*y;
					cout<<"\nThe answer is: " << result;
					break;

			case '/':
					 if (y ==0 )
					{
					  cout<<"\nThat is an invalid operation";
					}
					else
				   {
					 result = x/y;
					 cout<<"\nThe answer is: " << result;
				   }
					break;

			default :
					 cout<<"\nThat is an invalid operation";
					 break;
		}
	}while(op != 'Q');
	return 0;
}
