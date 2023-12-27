#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Base{ //Parent Class
    public:
    Base(){//virtual Base not possible// Ctor cannot be virtual as virtual requires some interface to refer to and if ctor is virtual class
                    // Object cannot be initialised as it will become virtual so no ctor cant be virtual
        cout<<"Base Ctor is Created "<<endl;
    }
    virtual ~Base(){ //Creating Virtual Base Dtor so that before destroying Base Class All Derived Class Dtor are called
        cout<<"Base Dtor is called "<<endl;
    }
};

class Derived : public Base{ //derived class of Base(child class)
    int *a ; //creating dynamic variable on Heap during Run time 
    public:
    Derived(){
        a = new int[1000] ;
        cout<<"Derived Class Ctor is called "<<endl;
    }
    ~Derived(){
        delete[] a;
        cout<<"Derived Dtor is called "<<endl;
    }
};

int main(){
    Base *b = new Derived ;
    delete b;
    return 0;
}
// first output :
// Base Ctor is Created
// Derived Class Ctor is called 
// Base Dtor is called
//Second Output:
// Base Ctor is Created
// Derived Class Ctor is called
// Derived Dtor is called
// Base Dtor is called