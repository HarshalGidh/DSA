#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class student
{
protected:
int rno,m1,m2;
public:
void get()
{
	cout<<"\nEnter Roll No:";
	cin>>rno;
	cout<<"\nEnter Marks of the two Subject:";
	cin>>m1>>m2;
}
};
class sports
{
protected:
int sm;
public:
void getsm()
{
	cout<<"\nEnter the Sports Marks:";
	cin>>sm;
}
};
class statement : public student, public sports
{
int tot, avg;
public:
void display()
{
tot=(m1+m2+sm);
avg=(tot*100)/300;
cout<<"\nTotal Marks:"<<tot;
cout<<"\nAverage:"<<avg;
}
};
int main()
{
statement obj;
obj.get();
obj.getsm();
obj.display();
return 0;
}

