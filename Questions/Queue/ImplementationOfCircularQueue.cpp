#include<iostream>
using namespace std;
class CQueue{
    public:
        int *arr; //dynamic array
        int size;
        int front;
        int rear;
        //creating default Constructor
        CQueue(int size){
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1 ;
        }
        void push(int val){
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
        void pop(){
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
    CQueue q(5);
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