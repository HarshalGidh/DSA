#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class complex
{
    float x,y; //x:real part; y:imaginary part
    
    public:
        void getdata();
        void show(complex);
        friend void sum(complex, complex);
        void sub(complex, complex);       
        void mul(complex, complex);
        void div(complex, complex);
        void conj(complex);
        void mod(complex);
        void arg(complex);
        void polar(complex);
};

void complex :: getdata()
{
    cout<<"Enter the real part of complex number"<<endl;
    cin>>x;
    cout<<"Enter the imaginary part of complex number"<<endl;
    cin>>y;
}

void sum(complex c1, complex c2)
{
    complex c3;
    c3.x = c1.x + c2.x;
    c3.y = c1.y + c2.y;
    cout<<"Z_sum= "<<c3.x<<" + j("<<c3.y<<")"<<endl;
}

void complex :: sub(complex c1, complex c2)
{
    complex c4;
    c4.x = c1.x - c2.x;
    c4.y = c1.y - c2.y;
    cout<<"Z_sub= "<<c4.x<<" + j("<<c4.y<<")"<<endl;
}

void complex :: mul(complex c1, complex c2)
{
    complex c5;
    c5.x = c1.x*c2.x - c1.y*c2.y;
    c5.y = c1.x*c2.y + c1.y*c2.x;
    cout<<"Z_mul= "<<c5.x<<" + j("<<c5.y<<")"<<endl;
}

void complex :: div(complex c1, complex c2)
{
    complex c6;
    c6.x = (c1.x*c2.x + c1.y*c2.y)/(c2.x*c2.x + c2.y*c2.y);
    c6.y = (c2.x*c1.y - c2.y*c1.x)/(c2.x*c2.x + c2.y*c2.y);
    cout<<"Z_div= "<<c6.x<<" + j("<<c6.y<<")"<<endl;
}

void complex :: conj(complex c)
{
    complex c7;
    c7.x = c.x;
    c7.y = -c.y;
    cout<<"Z_conj= "<<c7.x<<" + j("<<c7.y<<")"<<endl;
}

void complex :: mod(complex c)
{
    float r;
    r = sqrt(c.x*c.x + c.y*c.y);
    cout<<"Absolute value is= "<<r<<endl;
}

void complex :: arg(complex c)
{
    float rtheta, dtheta;
    rtheta = atan(c.y/c.x);
    dtheta = rtheta * 180/3.14;
    cout<<"Argument in radians is= "<<rtheta<<endl;
    cout<<"Argument in degrees is= "<<dtheta<<endl;
}

void complex :: polar(complex c)
{
    float r, rtheta, dtheta;
    r = sqrt(c.x*c.x + c.y*c.y);
    rtheta = atan(c.y/c.x);
    dtheta = rtheta * 180/3.14;
    cout<<"Polar form is= "<<r<<" e^j("<<dtheta<<")"<<endl;
}

void complex :: show(complex c)
{
    cout<<c.x<<" + j"<<c.y<<endl;
}

int main()
{
    int choice;
    char r;
    complex Z1,Z2,Z;

    do
    {
        cout<<" #### MENU ####"<<endl;
        cout<<" 1) Add"<<endl;
        cout<<" 2) Subtract"<<endl;
        cout<<" 3) Multiply"<<endl;
        cout<<" 4) Divide"<<endl;
        cout<<" 5) Conjugate"<<endl;
        cout<<" 6) Modulus/Absolute Value"<<endl;
        cout<<" 7) Argument"<<endl;
        cout<<" 8) Polar Form"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1 :
            {
                Z1.getdata();
                cout<<"Z1 = ";
                Z1.show(Z1);
                Z2.getdata();
                cout<<"Z2 = ";
                Z2.show(Z2);
                sum(Z1,Z2);
            }
            break;

            case 2 :
            {
                Z1.getdata();
                cout<<"Z1 = ";
                Z1.show(Z1);
                Z2.getdata();
                cout<<"Z2 = ";
                Z2.show(Z2);
                Z.sub(Z1,Z2);
            }
            break;

            case 3 :
            {
                Z1.getdata();
                cout<<"Z1 = ";
                Z1.show(Z1);
                Z2.getdata();
                cout<<"Z2 = ";
                Z2.show(Z2);
                Z.mul(Z1,Z2);
            }
            break;

            case 4 :
            {
                Z1.getdata();
                cout<<"Z1 = ";
                Z1.show(Z1);
                Z2.getdata();
                cout<<"Z2 = ";
                Z2.show(Z2);
                Z.div(Z1,Z2);
            }
            break;

            case 5 :
            {
                Z1.getdata();
                cout<<"Z1 = ";
                Z1.show(Z1);
                Z.conj(Z1);
            }
            break;

            case 6 :
            {
                Z1.getdata();
                cout<<"Z1 = ";
                Z1.show(Z1);
                Z.mod(Z1);
            }
            break;

            case 7 :
            {
                Z1.getdata();
                cout<<"Z1 = ";
                Z1.show(Z1);
                Z.arg(Z1);
            }
            break;

            case 8 :
            {
                Z1.getdata();
                cout<<"Z1 = ";
                Z1.show(Z1);
                Z.polar(Z1);
            }
            break;  
        }

        cout<<" Do you want to continue";
        cin>>r;

    }while(r!='n');
    
    return 0;
}


