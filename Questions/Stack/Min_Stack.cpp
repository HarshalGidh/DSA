// #include<iostream>
// // #include<stack>
// #include<string>
// #include<vector>
// using namespace std;
// class MinStack {
// public:
//     vector<pair<int,int>> st ; //creating vector(stack) with pair elements
//     MinStack() {
//         //no need
//     }
    
//     void push(int val) {
//         pair<int,int> p;
//         if(st.empty()){//solving for first element of Stack
//             p.first = val ;//first part being value
//             p.second = val ; //Second Value is min which is val for 1st element 
//             st.push_back(p); //inserting pair in stack
//         }
//         else{
//             p.first = val;//inserting value in pair's first
//             int prevMin = st.back().second ; //getting previous elements min from stack 
//             p.second = min(prevMin,val) ;//minimum of prevMin and val will be new min
//             st.push_back(p); //inserting p in stack
//         }
//     }
    
//     void pop() {
//         if(st.empty()){
//             return; //stack underflow condition so return nothing
//         }
//         else{
//             st.pop_back(); 
//         }
//     }
    
//     int top() {
//         if(!st.empty()){
//             pair<int,int> rightMost = st.back();
//             return rightMost.first; //returning R.M. First as it contains the value
//         }
//         else{
//             return 0 ;
//         }
//     }
    
//     int getMin() {
//         if(!st.empty()){
//             pair<int,int> rightMost = st.back();
//             return rightMost.second;//returning Minimum of Stack stored in second of R.M.
//         }
//         else{
//             return 0 ;
//         }
//     }
//     //making printing statement for our own purposes
//    void print() {
//     for (const auto& p : st) {
//         cout << p.first << " ";
//     }
//     cout << endl;
//     }

// };
// int main(){
//     MinStack minstack;
//     minstack.push(2);
//     minstack.push(1);
//     minstack.push(4);
//     minstack.push(3);
//     minstack.push(5);
//     minstack.print();
//     minstack.pop();
//     minstack.print();
//     cout<<minstack.getMin();
//     // if(ans){
//     //     cout<<"Redundant Brackets Present"<<endl;
//     // }
//     // else{
//     //     cout<<"No Redundant Brackets"<<endl;
//     // }
//     return 0;
// }
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class MinStack {
public:
    vector<pair<int, int>> st; // creating vector(stack) with pair elements

    MinStack() {
        // no need
    }

    void push(int val) {
        pair<int, int> p;
        if (st.empty()) { // solving for the first element of Stack
            p.first = val;      // first part being value
            p.second = val;     // Second Value is min which is val for the 1st element
            st.push_back(p);    // inserting pair in stack
        } else {
            p.first = val;               // inserting value in pair's first
            int prevMin = st.back().second; // getting the previous element's min from stack
            p.second = min(prevMin, val);  // minimum of prevMin and val will be the new min
            st.push_back(p);               // inserting p in stack
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop_back();
        }
    }

    int top() {
        if (!st.empty()) {
            pair<int, int> rightMost = st.back();
            return rightMost.first; // returning R.M. First as it contains the value
        } else {
            return 0;
        }
    }

    int getMin() {
        if (!st.empty()) {
            pair<int, int> rightMost = st.back();
            return rightMost.second; // returning Minimum of Stack stored in the second of R.M.
        } else {
            return 0;
        }
    }

    // making printing statement for our purposes
    void print() {
        for (const auto& p : st) {
            cout << p.first << " ";
        }
        cout << endl;
    }
};

int main() {
    MinStack minstack;
    minstack.push(2);
    minstack.push(1);
    minstack.push(4);
    minstack.push(3);
    minstack.push(5);
    minstack.print();
    minstack.pop();
    minstack.print();

    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */