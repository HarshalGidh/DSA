#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> ch ; //creating stack
        for(int i = 0; i<s.size();i++){
            char bracket = s[i] ;
            //take open bracket in stack
            if(bracket == '('  || bracket == '{' || bracket == '['){
                ch.push(bracket);
            }
            else if(bracket == ')'  || bracket == '}' || bracket == ']'){
                //closing bracket found check for its respective open bracket
                //check if stack is empty or not to avoid underflow case
                if(!ch.empty()){
                    if(bracket == ')' && ch.top() == '('){
                        ch.pop(); //pop the bracket
                    }
                    else if(bracket == '}' && ch.top() == '{' ){
                        ch.pop();
                    }
                     else if(bracket == ']' && ch.top() == '['){
                         ch.pop() ;
                     }
                     else{ 
                     //if there is a closing bracket but we dont have its respective 
                     //open bracket so invalid hence return false
                         return false ;
                     }
                }
                else{
                    //stack is empty we cant pop but there are closing brackets in str so 
                    //false
                    return false;
                }
            }
        }
        //if we reached here so we have traversed the str    
        //check if stack is empty or not
        if(ch.empty()){
            return true ; //stack empty valid parenthesis
        }
        else{
            return false ;
        }
    }
};
int main(){
    Solution s;
    bool ans;
    string str = {"({[]}"} ;
    ans = s.isValid(str);
    if(ans){
        cout<<"Valid Parenthesis"<<endl;
    }
    else{
        cout<<"Invalid Parenthesis"<<endl;
    }
    return 0;
}