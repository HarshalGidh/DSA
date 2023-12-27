//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n==0){ //Base Case
            return 0; //valid number of cuts
        }
        if(n < 0){
            return  INT_MIN;
        }
        //One x cut is made the rest x cuts will be handled by recursion
        int option1 = 1 + maximizeTheCuts(n-x,x,y,z);
        //One y cut is made the rest x cuts will be handled by recursion
        int option2 = 1 + maximizeTheCuts(n-y,x,y,z);
        //One z cut is made the rest x cuts will be handled by recursion
        int option3 = 1 + maximizeTheCuts(n-z,x,y,z);
        //the max of opt1 ,2 or 3 will be our answer
        int finalAns = max(option1 ,max(option2,option3));
        return finalAns ; 
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code 