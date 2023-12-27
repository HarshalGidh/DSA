#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    vector<int> nextSmallestInteger(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1); //pushing -1 for stack to not be empty and acting it as prev at first
        //finding and storing indexes smalller than the curr bar
        for(int i = arr.size()-1; i >=0;i--){
            int curr = arr[i];
            //find ans for curr
            while(st.top() != -1 && !st.empty() && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top(); //storing the index of the next smallest bar
            st.push(i);
        }
        return ans ;
    }
    vector<int> prevSmallestInteger(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1); //pushing -1 for stack to not be empty and acting it as prev at first
        //finding and storing indexes smalller than the curr bar
        for(int i = 0;i< arr.size();i++){
            int curr = arr[i];
            //find ans for curr
            while(st.top() != -1 && !st.empty() && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top(); //storing the index of the next smallest bar
            st.push(i);
        }
        return ans ;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallestInteger(heights);
        vector<int> prev = prevSmallestInteger(heights);
        for(int i =0;i<heights.size();i++){
            if(next[i] == -1){
                next[i] = heights.size();
            }
        }
        int width = 1;
        vector<int> area(heights.size());
        for(int i = 0;i<heights.size();i++){
            width = next[i] - prev[i] - 1; //this gives us the width
            int length = heights[i];
            area[i] = length * width ;
        }
        int maxi = INT_MIN ;
        for(int i =0;i<heights.size();i++){
            //getting max area
            maxi = max(maxi,area[i]) ;
        }
        return maxi ;
    }
};
int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    int size = 6;
    Solution s;
    int ans ;
    ans = s.largestRectangleArea(arr);
    // Print the ans of max
    
    cout << ans <<endl;
    

    return 0;
}