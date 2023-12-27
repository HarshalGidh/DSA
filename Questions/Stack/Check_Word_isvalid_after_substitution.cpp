#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        //Recursive Method : T.C. = O(n^2)
        // //Base Case:
        // if(s.size() == 0){
        //     return true; //string is empty/null so valid string
        // }
        // int found = s.find("abc") ;//returns starting index of abc
        // while(found != string::npos ){
        //     //when abc is found :
        //     string tleft = s.substr(0,found);//left str from 0 till starting index of abc
        //     string tright = s.substr(found + 3, s.size());// right str found+3 as abc =3(size)
        //     //recursive call :
        //     return isValid(tleft + tright);
        // }
        // return false; //s string cant become null so invalid


        //Stack approach :
        if(s[0] != 'a'){
            return false; //as no abc can be formed if s[0] != 'a'
        }
        stack<char>st;
        for(char ch : s){
            if(ch == 'a'){
                st.push(ch);
            }
            else if(ch == 'b'){
                if(!st.empty() && st.top() == 'a'){
                    st.push(ch);
                }
                else{
                    return false;
                }
            }
            else{
                //ch == 'c'
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop(); //removed ab from stack and hence abc is removed
                    }
                    else{
                        return false; //top is not a but b or c
                    }
                }
                else{
                    return false;
                }
            }
        }
        return st.empty() ;
    }
};
int main(){
    Solution sol;
    if(sol.isValid("aabcbc")){
        cout<<"Valid string "<<endl;
    }
    else{
        cout<<"Invalide String "<<endl;
    }
    return 0;
}