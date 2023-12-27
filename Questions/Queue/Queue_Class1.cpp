#include<iostream>
#include<queue>
using namespace std;
int main(){
    //creation 
    queue<int> q ;

    //inserting element in queue
    q.push(5);

    //size
    cout<<"The size of Queue is : "<<q.size()<<endl;

    //empty 
    if(q.empty()){
        cout<<"The Queue is empty "<<endl;
    }
    else{
        cout<<"Queue is not empty "<<endl;
    }

    //remove
    q.pop();

     //size
    cout<<"The size of Queue is : "<<q.size()<<endl;

     //empty 
    if(q.empty()){
        cout<<"The Queue is empty "<<endl;
    }
    else{
        cout<<"Queue is not empty "<<endl;
    }

    q.push(10);
    q.push(20);
    q.push(30);

    //Front element
    cout<<"Front element of queue is : "<<q.front()<<endl;

    //end element
    cout<<"Last element of queue is : "<<q.back()<<endl;

    return 0;
}