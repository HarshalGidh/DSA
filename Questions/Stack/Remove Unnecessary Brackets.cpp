#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st ; //creating stack
        int operatorCount = 0;
        for(int i = 0; i<s.size();i++){
            char ch = s[i] ;
            //take open bracket and operators in stack
            if(ch == '('  || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch);
            }
            else if(ch == ')' ){
                //closing bracket found count number of operators
                //check if stack is empty or not to avoid underflow case
                if(!st.empty()){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                        while(st.top() != '('){ //count number of operators presnet between Open Bracket and Closed Bracket
                            operatorCount++;
                            st.pop(); //pop the operator
                        }
                    }
                    if(st.top() == '(' ){
                        if(operatorCount > 0){
                            st.pop() ; //remove open Bracket
                        }
                        else{
                            return true; //redundant brackets present
                        }
                    }
                }
                else{ 
                //if there is a closing bracket but we dont have its respective 
                //open bracket so invalid hence return false
                    return true ;
                }
            }
               
            }
        //if we reached here so we have traversed the str    
        //check if stack is empty or not
        if(st.empty()){
            return false ; //No redundant parenthesis present
        }
        else{
            return true ;
        }
    }
};
int main(){
    Solution s;
    bool ans;
    string str = {"((a)+b)"} ;
    ans = s.isValid(str);
    if(ans){
        cout<<"Redundant Brackets Present"<<endl;
    }
    else{
        cout<<"No Redundant Brackets"<<endl;
    }
    return 0;
}