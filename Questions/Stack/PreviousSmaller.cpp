// #include<iostream>
// #include<stack>
// #include<string>
// #include<vector>
// using namespace std;

// vector<int> prevSmaller(int *arr, int size) {
//     vector<int> ans(size);
//     stack<int> st;
//     st.push(-1); // as the last element's next smaller will not exist we take -1
//     for (int i = 0 ; i < size ; i++) {
//         int curr = arr[i];
//         while (!st.empty() && st.top() >= curr) {
//             st.pop();
//         }
//         ans[i] = (st.empty() ? -1 : st.top()); // if stack is empty, set -1
//         st.push(curr); // pushing curr in stack
//     }
//     return ans;
// }

// int main() {
//     int arr[] = {8, 4, 6, 2, 3};
//     int size = 5;
//     vector<int> ans = prevSmaller(arr, size);
//     for (auto i : ans) {
//         cout << i << " ";
//     }

//     return 0;
// }
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

vector<int> prevSmaller(int *arr, int size , vector<int> &ans) {
    //vector<int> ans(size);
    stack<int> st;
    st.push(-1); // as the last element's next smaller will not exist we take -1
    for (int i = 0 ; i < size ; i++) {
        int curr = arr[i];
        while (st.top() >= curr) {
            st.pop();
        }
        ans[i] = st.top(); // if stack is empty, set -1
        st.push(curr); // pushing curr in stack
    }
    
    return ans;
}

int main() {
    int arr[] = {8, 4, 6, 2, 3};
    int size = 5;
    vector<int> ans(size) ;
    ans = prevSmaller(arr, size , ans);
    // Print the ans vector
    for (auto i : ans) {
        cout << i << " ";
    }
    

    return 0;
}
