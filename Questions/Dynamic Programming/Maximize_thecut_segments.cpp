#include <bits/stdc++.h> 
using namespace std; 
    
// A Dynamic Programming solution for 
// Maximum Rod cutting problem 
// function that returns the maximum 
// number of rods that can be 
// made from the rod of length N 

int cuttingRod(int arr[], int N) 
{ 
	int dp[N + 1]; 

	// Initializing the number of rods we 
	// can make from length 0 
	dp[0] = 0; 

	// Iterating over lengths that can 
	// be formed 
	for (int i = 1; i <= N; i++) { 

		// Initializing the possible 
		// cuts as infinite 
		dp[i] = INT_MIN; 

		// Cutting the desired lengths 
		for (int j = 0; j < 3; j++) { 

			// Checking whether the length of 
			// rod becomes 0 or if after cutting 
			// the rod, it becomes useless 
			if ((i - arr[j]) >= 0 
				&& dp[i - arr[j]] != INT_MIN) { 

				// Choosing the maximum 
				// possible desired 
				// length cuts to be made 
				dp[i] = max(dp[i - arr[j]] + 1, 
							dp[i]); 
			} 
		} 
	} 
	return dp[N]; 
} 
class Solution
{
    public:
    int solve(int n,int x,int y,int z){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        int p=solve(n-x,x,y,z)+1;
        int q=solve(n-y,x,y,z)+1;
        int r=solve(n-z,x,y,z)+1;
        return max(p,max(q,r));
    }
    int solveTopDown(int n,int x,int y,int z,vector<int>&dp){
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        if(dp[n]!=-1)return dp[n];
        int p=solveTopDown(n-x,x,y,z,dp)+1;
        int q=solveTopDown(n-y,x,y,z,dp)+1;
        int r=solveTopDown(n-z,x,y,z,dp)+1;
        return dp[n]= max(p,max(q,r));
    }
    int solveBottomUp(int n,int x,int y,int z){
        vector<int>dp(n+1,INT_MIN);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            //checking if lenght of rod becomes >=0(possible to cut) or becomes useless(INT_MIN)
            //cant cut the rod 
            if(i-x>=0 && dp[i -x] != INT_MIN ){
                dp[i]=max(dp[i],dp[i-x]+1);
            }
            if(i-y>=0 && dp[i -y] != INT_MIN){
                dp[i]=max(dp[i],dp[i-y]+1);
            }
            if(i-z>=0 && dp[i -z] != INT_MIN){
                dp[i]=max(dp[i],dp[i-z]+1);
            }
        }
        return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        // return solve(n,x,y,z)!=INT_MIN ? solve(n,x,y,z) : 0;
         vector<int>dp(n+1,-1);
        return max(solveTopDown(n,x,y,z,dp),0);
       // return max(solveBottomUp(n,x,y,z),0);
    }
};    

// Driver code 
int main() 
{ 
	int N = 17; 
	int arr[] = { 10, 11, 3 }; 
	cout << cuttingRod(arr, N); 
    cout<<endl;
    Solution s;
    int x = 10,y = 11, z= 3;
    int n = 17;
    cout<<"The ans is : "<<s.maximizeTheCuts(n,x,y,z);
	return 0; 
} 