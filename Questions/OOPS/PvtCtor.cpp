#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Box{

    int width ;
    Box(int _w):width(_w){} //Private Ctor
    public :
        

        int getWidth() const{
            //Getter : It gets values(data members) from Private Section of the class
            return width ;
        }
        int setWidth(int _val) {
            //Setter : It sets the value for Private Data variables or Data Members 
            width = _val ;

        }
        friend class BoxFactory ;
};

class BoxFactory{
    int count ; //counts number of boxes
    public:
        Box getABox(int _w){
            ++count;
            return Box(_w);
        }
};

int main(){
    BoxFactory bfact;
    Box b = bfact.getABox(10);
    cout<< b.getWidth() <<endl;
    return 0;
}