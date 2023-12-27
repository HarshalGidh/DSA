#include<iostream>
using namespace std;
class Deque{
    public:
        int *arr; //dynamic array
        int size;
        int front;
        int rear;
        //creating default Constructor
        Deque(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1 ;
        }
        void push_front(int val){
            if(front == 0){
                //queue is already full
                cout<<"Overflow ";
                return;
            }
            else if(front == -1 && rear == -1){
                //empty case
                front++;
                rear++;
                arr[front] = val ;
            }
            else if(front == 0 && rear != size -1){
                front = size - 1; //going back to the starting obeying circular nature
                arr[front] = val ;
            }
            else{
                //normal case
                front--;
                arr[front] = val;
            }
        }
        void push_back(int val){
            //overflow
            if((rear == size - 1) || (rear = front - 1)){ //if rear is just behind front pushing will lead to overflow 
                //queue is already full
                cout<<"Queue Overflow ";
                return;
            }
            //empty case
            else if(front == -1 && rear == -1){
                //empty case
                front++;
                rear++;
                arr[rear] = val ;
            }
            //circular nature
            else if(rear == size - 1 && front != 0){
                rear = 0; //going back to the starting obeying circular nature
                arr[rear] = val ;
            }
            else{
                //normal case
                rear++;
                arr[rear] = val;
            }
        }
        void pop_front(){
            //check underflow case when queue is empty 
            if(front == -1 && rear == -1){
                cout<<"Queue Underflow ";
            }
            //single / 1 element case
            else if(front == rear){
                //single element
                arr[front] = -1 ;
                front = -1;
                rear = -1;
            }
            else if(front == size - 1){
                arr[front] = -1;
                front = 0; //going back to start obeying circular nature 
                
            }
            else{
                //not empty
                arr[front] = -1 ;
                front++;
            }
        }
        void pop_back(){
            //underflow
            if(front == -1 && rear == -1){
                cout<<"Underflow ";
            }
            //single element case
            else if(front == rear){
                //single element
                arr[rear] = -1 ;
                front = -1;
                rear = -1;
            }
            else if(rear == 0){
                arr[rear] = -1;
                rear = size -1;
            }
            else{
                arr[rear] = -1;
                rear--;
            }
        }
        bool empty(){
            if(front == -1 && rear == -1){
                return true ;
            }
            else{
                return false;
            }
        }
        int Size(){
            if(front == -1 && rear == -1){
                //empty case
                return 0;
            }
            else{
                return rear - front + 1;
            }
        }
        int getFront(){
            if(front == -1){
                //empty case
                cout<<"Queue is empty cant return Front Element "<<endl;
                return -1;
            }
            else{
                return arr[front];
            }
        }
        int getRear(){
            if(rear == -1){
                //empty case
                cout<<"Queue is empty cant return Rear element "<<endl;
            }
            else{
                return arr[rear];
            }
        }
        void print(){
            //just for us to check queue elements
            cout<<"Printing Queue elements : ";
            for(int i = 0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    Deque dq(5);
    dq.print();
    cout<<endl;
    dq.push_front(10);
    dq.print();

    dq.push_back(20);
    dq.print();

    dq.push_front(30);
    dq.print();

    dq.push_back(40);
    dq.print();

    dq.push_front(50);
    dq.print();

    cout<<"Size of Deque is : "<<dq.Size()<<endl;

    dq.pop_back();
    dq.print();
    cout<<"Size of Deque is : "<<dq.Size()<<endl;
    cout<<"DeQue is empty or not :"<<dq.empty()<<endl;
    dq.pop_back();
    dq.print();
    dq.pop_front();
    dq.print();
    return 0;
}