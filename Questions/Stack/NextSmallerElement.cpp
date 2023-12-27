// #include<iostream>
// #include<stack>
// #include<string>
// #include<vector>
// using namespace std;
// vector<int> nextSmaller(int *arr,int size,int &ans){
//     stack<int> st;
//     st.push(-1) ; //as last elements next smaller will not exist we take -1
//     for(int i = size - 1;i>=0;i--){
//         int curr = arr[i] ;
//         while(st.top() >= curr){ //checks for next smaller 
//             st.pop() ;
//         }
//         ans[i] = st.top() ;//pushing top in ans as it is next smaller for curr
//         st.push(curr) ; //pushing curr in stack 
//     }
//     return ans ;
// }

// int main(){
//     int arr[5] = {8,4,6,2,3} ;
//     int size = 5 ;
//     vector<int> ans(size);
//     ans = nextSmaller(arr,size,ans) ;
//     for(auto i : ans){
//         cout<<i<<" ";
//     }

//     return 0;
// }
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

vector<int> nextSmaller(int *arr, int size) {
    vector<int> ans(size);
    stack<int> st;
    st.push(-1); // as the last element's next smaller will not exist we take -1
    for (int i = size - 1; i >= 0; i--) {
        int curr = arr[i];
        while (!st.empty() && st.top() >= curr) {
            st.pop();
        }
        ans[i] = (st.empty() ? -1 : st.top()); // if stack is empty, set -1
        st.push(curr); // pushing curr in stack
    }
    return ans;
}



int main() {
    int arr[] = {8, 4, 6, 2, 3};
    int size = 5;
    vector<int> ans = nextSmaller(arr, size);
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}
