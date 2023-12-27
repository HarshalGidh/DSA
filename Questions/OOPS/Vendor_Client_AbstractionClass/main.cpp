#include<iostream>
#include "bird.h"
using namespace std;

void birdDoesSomething(Bird*&bird){
    bird->eat() ;
    bird->fly() ;
    bird->eat() ;
    bird->fly() ;
}
int main(){
    Bird *bird = new eagle() ;
    birdDoesSomething(bird);
   // Bird *b2 = new Bird(); cant instantiate object of these classes as its an interface
    return 0;
}