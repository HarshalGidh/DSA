#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        //Step 1: Put all people in a stack :
        for(int i = 0;i<n;i++){
            st.push(i);
        }
        //Step 2: Discard all the non celebs to get 1 possible Celebrity
        while(st.size() != 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(M[a][b]){//if a knows b :
                st.push(b);//discard a as it knows b , b might be a celebrity
            }
            else{
                st.push(a);//ignore b, a might be a celebrity
            }
        }
        //we have an element in stack which is most likely celbrity
        int mightBeCelebrity = st.top();
        st.pop();
        //Step 3 : Check whether celebrity knows anyone if yes then not celebrity
        for(int i = 0;i<n;i++){
            if(M[mightBeCelebrity][i] != 0){//if celebrity lnows anyone
                return -1; //not celebrity
            }
        }
        //Check whether everyone else knows celebrity
        for(int i = 0;i<n;i++){
            if(M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity){//other than celebrity someone doesnt know celebrity
                return -1; //not a celeb
            }
        }
        return mightBeCelebrity;
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