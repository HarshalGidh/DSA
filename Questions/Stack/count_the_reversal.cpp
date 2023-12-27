#include<iostream>
#include<stack>
#include<string>
using namespace std;

int countRev (string s)
{
    if(s.size() & 1){//odd string so inbalance
        return -1;
    }
    int count = 0;
    stack<char> st;
    for(char ch : s){
        if(ch == '{'){ //opening bracket found
            st.push(ch);
        }
        else{ //ch =='}' found
            if(!st.empty() && st.top() == '{'){
                st.pop(); //valid pair
            }
            else{
                st.push(ch);
            }
        }
    }
    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top(); //no need to check for st is empty as there will always be 2 pairs else str is odd and invalid
        st.pop();
        if(a == b){//same brackets
            count+= 1;
        }
        else{
            count+= 2; //different brackets 
        }
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    string s;
    s = "}{{}}{{{";
    cout<<countRev(s)<<"\n";
    // while(t--){
    //     cout<<countRev(s)<<"\n";
    // }
    return 0;
}