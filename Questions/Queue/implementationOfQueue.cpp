#include<iostream>
using namespace std;
class Queue{
    public:
        int *arr; //dynamic array
        int size;
        int front;
        int rear;
        //creating default Constructor
        Queue(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1 ;
        }
        void push(int val){
            if(rear == size - 1){
                //queue is already full
                cout<<"Queue Overflow ";
                return;
            }
            else if(front == -1 && rear == -1){
                //empty case
                front++;
                rear++;
                arr[rear] = val ;
            }
            else{
                //normal case
                rear++;
                arr[rear] = val;
            }
        }
        void pop(){
            //check underflow case when queue is empty 
            if(front == -1 && rear == -1){
                cout<<"Queue Underflow ";
            }
            else if(front == rear){
                //single element
                arr[front] = -1 ;
                front = -1;
                rear = -1;
            }
            else{
                //not empty
                arr[front] = -1 ;
                front++;
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
    Queue q(5);
    q.print();
    cout<<endl;
    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();

    q.push(50);
    q.print();

    cout<<"Size of Queue is : "<<q.Size()<<endl;

    q.pop();
    q.print();
    cout<<"Size of Queue is : "<<q.Size()<<endl;
    cout<<"Queue is empty or not :"<<q.empty()<<endl;

    return 0;
}