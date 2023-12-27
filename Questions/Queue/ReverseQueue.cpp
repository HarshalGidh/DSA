#include<iostream>
#include<stack>
#include<queue>
#include<deque>
using namespace std ;
void reverseQueue(queue<int> &q){
    stack<int> st;
    //removing elements from queue and storing stack
    while(!q.empty()){
        int frontElement = q.front();//storing front element
        q.pop();//removing front element
        st.push(frontElement); //storing in stack
    }
    //removing elements from stack and storing againg in queue hence reversing queue
    while(!st.empty()){
        int topElement = st.top(); //storing top element
        st.pop();
        q.push(topElement);
    }
}
void reverse(queue<int> &q){
    //Base Case
    if(q.empty()){
        return; //no more elements go back
    }
    // 1 case ka solving
    int element = q.front();
    q.pop();
    //recursion call :
    reverse(q);
    //BackTracking :
    q.push(element) ;
}
void reverseKelements(queue<int> &q,int &k){
    stack<int> st;
    int n = q.size() ;
    if(k >n || k == 0){ //cant reverse k elements greater than n or if k is 0
        return;
    }
    //removing k elements from queue and storing in stack :
    for(int i = 0;i<k;i++){
        int temp = q.front();
        q.pop();
        st.push(temp);
    }
    //reversing k elements by storing elements of stack in queue
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        q.push(temp);
    }
    //now (n-k) elements are ahead of our reversed elements so we pop them from queue and push it end
    for(int i = 0;i<(n - k);i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
   
}
void rearrangeQueue(queue<int> &q){
        queue<int> second;
        int size = q.size();
        //Breaking the main queue into 2 halves
        for(int i = 0;i<size/2;i++){
            int temp = q.front();
            q.pop();
            second.push(temp);
        }
        //now merging them or interleaving the 2 queues
        for(int i = 0 ;i<size/2;i++){
            int temp = second.front();
            second.pop();
            q.push(temp); //pushing second queue into the first
            temp = q.front(); //getting second half first element
            q.pop();
            q.push(temp); //pushing second half into first queue
        }
}
void printFirstNegativeNumber(int *arr,int n,int k){
    deque<int> dq;

    //process first k elements - first window
    for(int index = 0;index < k ;index++){
        int element = arr[index];//getting element
        if(element < 0){
            dq.push_back(index);
        }
    }
    //process remaining windows - Removal and Addition of elements from the window
    for(int index = k;index<n;index++){
        //previous window answer :
        if(dq.empty()){
            cout<<"0"<<endl; //0 means no negative number in that window(1st window)
        }
        else{
            cout<<arr[dq.front()]<<" ";
        }
        //Removal -removing indexes stored inside deque if its no longer in window
        if(index - dq.front() >= k ){
            dq.pop_front(); //removing front element from dq
        }
        //Addition - adding new index in Deque if element is negative
        if(arr[index] < 0){
            dq.push_back(index); //new negative number's index getting stored
        }
    }
    //last window answer : as we cant print answer for last window inside for loop we do it here
    if(dq.empty()){
        cout<<"0"<<endl; //0 means no negative number in that window(last window)
    }
    else{
        cout<<arr[dq.front()]<<" ";
    }
}

int main(){
    queue<int> q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // reverseQueue(q);
    // cout<<"Printing Reverse Queue :"<<endl;
    // while(!q.empty()){
    //     int element =q.front();
    //     q.pop();
    //     cout<<element<<" ";
    // }
    // cout<<endl;
    // //using recurdsion :
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // reverse(q);
    // cout<<"Printing Reverse Queue using recursion:"<<endl;
    // while(!q.empty()){
    //     int element =q.front();
    //     q.pop();
    //     cout<<element<<" ";
    // }
    // cout<<endl;
    // //reversing k elements :
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // int k = 3 ; // k must be smaller than or equal to q.size()
    // reverseKelements(q,k);
    // cout<<"Printing Reverse Queue after reversing "<<k<<" elements : "<<endl;
    // while(!q.empty()){
    //     int element =q.front();
    //     q.pop();
    //     cout<<element<<" ";
    // }
    // // interleave first and second half of queue :
    // cout<<endl;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // rearrangeQueue(q);
    // cout<<"Printing Interleave Queue: "<<endl;
    // while(!q.empty()){
    //     int element =q.front();
    //     q.pop();
    //     cout<<element<<" ";
    // }
    //Printing First Negative Number inside a window :
    int arr[] = {2,-5,4,-1,-2,0,5};
    int size = 7;
    int k = 3;
    printFirstNegativeNumber(arr,size,k);
    return 0;
}