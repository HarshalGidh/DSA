#include<iostream>
#include<deque>
using namespace std ;
int main(){
    deque<int> dq;
    dq.push_front(10);
    dq.push_back(20);
    cout<<"Front : "<<dq.front()<<endl;
    cout<<"Rear : "<<dq.back()<<endl;
    dq.pop_front();
    cout<<"Front : "<<dq.front()<<endl;
    cout<<"Size : "<<dq.size()<<endl;
    return 0;
}