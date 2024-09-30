#include<iostream>
#include<iomanip>
using namespace std;
class index
{
    public:
    int count;

    index()  //zero argument constructor
    {
        count=0;
    }

    index(int i)  //parameterized constructor
    {
        count = i;
    }

    index operator++()  //zero argument function to increment count by 1
    {
        ++count;
    }

    void showdata()
    {
        cout<<count;
    }
};

int main()
{
    index c;
    
    cout<<endl<<"c=";
    c.showdata();
    
    ++c;
	cout<<endl<<"c=";
    c.showdata();

    ++c;
    cout<<endl<<"c=";
    c.showdata();

    ++c;
    cout<<endl<<"c=";
    c.showdata();

    return 0;
}

