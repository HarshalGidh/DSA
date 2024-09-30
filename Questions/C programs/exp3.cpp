#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class prime
{
    public:
    int a,num;

    int getdata()
    {
        cout<<endl<<"Enter any integer:";
        cin>>num;
        return(num);
    }

    prime()  //Zero argument Constructor
    {
        a=num;
    }

    ~prime()  //Destructor
    {
    }
};

int main()
{
    prime p;
    int i, a, count=0;
    
    a = p.getdata();

    for (i=1; i<=a; i++)
    {
        if(a%i == 0)
        {
            count++;
        }
    }

    if (count==2)
    {
        cout<<"The given no "<<a<<" is prime number"<<endl;
    }
    else
    {
        cout<<"The given no "<<a<<" is NOT a prime number"<<endl;
    }

    return 0;
}

