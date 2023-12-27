#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Animal{
    public:
        virtual void sound(){
            cout<<"Animal making sound"<<endl;
        }
};

class Dog:public Animal{
    public:
        void sound(){
            cout<<"Dog making sound"<<endl;
        }
};
class Cat :public Animal{
    public:
        void sound(){
            cout<<"Cat making sound"<<endl;
        }
};
void sound(Animal *animal){
    animal->sound();
    return;
}
int main(){
    Animal *animal = new Dog();
    sound(animal);
    animal = new Cat();
    sound(animal);
    delete animal;
    return 0;
}