#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class c_polygon
{
protected:
float a,b;
public:
void get_data()
{
cout<<"\nEnter any two floating values:\n";
cin>>a>>b;
}
virtual float area()
{
return 0;
}
};
class c_rectangle : public c_polygon
{
public:
float area()
{
return (a*b);
}
};
class c_triangle : public c_polygon
{
public:
float area()
{
return (b*a/2);
}
};
int main()
{
c_rectangle r;
c_triangle t;
c_polygon *p;
p=&r;
p->get_data();
cout<<"\nArea of rectangle is "<<p->area();
p=&t;
p->get_data();
cout<<"\nArea of triangle is "<<p->area();
return 0;
}


