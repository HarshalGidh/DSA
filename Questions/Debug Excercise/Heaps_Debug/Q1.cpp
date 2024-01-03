/*Median of Stream of Running Integers using STL*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void printMedians(double arr[], int n)
{
	priority_queue<double> s;
	priority_queue<double,vector<double>,greater<double> > g;
	double med = arr[0];
	s.push(arr[0]);
	cout << med << endl;
	for (int i=1; i < n; i++)
	{
		double x = arr[i];
		if (s.size() < g.size())
		{
			if (x < med)
			{
				g.push(s.top());
				s.pop();
				s.push(x);
			}
			else
				g.push(x);

			med = (s.top() + g.top())/2.0;
		}
		else if (s.size()!=g.size())
		{
			if (x < med)
			{
				s.push(x);
				med = (double)s.top();
			}
			else
			{
				g.push(x);
				med = (double)g.top();
			}
		}
		else
		{
			if (x > med)
			{
				s.push(g.top());
				g.pop();
				g.push(x);
			}
			else
				s.push(x);

			med = (s.top() + g.top())/2.0;
		}

		cout << med << endl;
	}
}
int main(){
    double arr = {1,2,3,4,5,6};
    int n = 6;
    printMedians(arr,n);
    return 0;
}