#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>

class Bird{
    public:
        virtual void eat() = 0;
        virtual void fly() = 0;
        //All Classes that inherits this class has to 
        //implement pure virtual class
};
class sparrow: public Bird{
    public:
        void eat(){
            std::cout<<"Sparrow is Eating\n";
        }
        void fly(){
            std::cout<<"Sparrow is Flying\n";
        }
};
class eagle: public Bird{
    public:
        void eat(){
            std::cout<<"Eagle is Eating\n";
        }
        void fly(){
            std::cout<<"Eagle is Flying\n";
        }
};

#endif // BIRD_H
