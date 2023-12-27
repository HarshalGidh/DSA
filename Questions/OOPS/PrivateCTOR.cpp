#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Box(){
    int width ;
    public :
        Box(int _w):width(_w){}

        int getWidth() const{
            //Getter : It gets values(data members) from Private Section of the class
            return width ;
        }
        int setWidth(int _val) {
            //Setter : It sets the value for Private Data variables or Data Members 
            width = _val ;

        }
};
int main(){
    Box b(5);
    cout<<b.getWidth()<<endl;
    return 0;
}