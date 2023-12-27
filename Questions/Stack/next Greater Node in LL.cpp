/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> LL;
        while(head){//removing LL and storing its elements in an aray
            LL.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        for(int i =0;i<LL.size();i++){
            while(!st.empty() && LL[st.top()] < LL[i]){//if element in stack is less than LL[i]
                int stackElements = st.top();
                st.pop();
                LL[stackElements] = LL[i]; //storing next greater element in the ans
            }
            st.push(i); //storing next greater element in stack
        }
        while(!st.empty()){
            LL[st.top()] = 0; //as theres no next greater element for stackElements we take 0
            st.pop();
        }
        return LL;
    }
    vector<int> nextLargerNodes_usingPair(ListNode* head) {
        // Creating a stack of pairs to hold index-value pairs
        stack<pair<int, int>> st;
        // Creating a vector to store the final result
        vector<int> ans;
        // Index variable 'i' to keep track of the current index
        int i = 0;
        // Iterate through the linked list until head becomes NULL
        while(head){
        // Add a placeholder (0) to the answer vector for the current node
        ans.push_back(0);
        // Check if the stack is not empty and the current node's value is greater
        // than the value at the top of the stack. If true, update the answer vector.
        while(!st.empty() && st.top().second < head->val){
            auto top = st.top();
            st.pop();
            ans[top.first] = head->val;
        }
        // Push the current index-value pair into the stack
        st.push({i++, head->val});
        // Move to the next node in the linked list
        head = head->next;
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<vector<int> >M(n,vector<int> (n,0));
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>M[i][j];
        }
    }
    Solution sol;
    cout<<"The celebrity is :"<<sol.celebrity(M,n)<<endl;
    return 0;
}