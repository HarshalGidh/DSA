#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(int n){
        if(n == 0 || n == 1) return n;
        int ans = solveUsingRecursion(n - 1) + solveUsingRecursion(n - 2);
        return ans;
    }
    int solveUsingMemoisation(int n,vector<int>&dp){
        //Base Case
        if(n == 0 || n == 1) return n;
        //check if ans is stored else return 
        if(dp[n] != -1){
            return dp[n];
        }
        //store ans in dp array :
        dp[n] = solveUsingMemoisation(n - 1,dp) + solveUsingMemoisation(n - 2,dp);
        return dp[n];
    }
    int solveUsingTabularisation(int n){
        //Create DP array :
        vector<int>dp(n+1,-1);
        //analyse the conditions of base case and fill dp array
        dp[0] = 0;
        if(n == 0) return 0;
        dp[1] = 1;
        for(int i = 2;i<n+1;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int solveUsingStorageOptimization(int n){
        int prev  = 0;
        if(n == 0) return 0;
        int curr = 1;
        if(n == 1) return 1;
        int ans ;
        for(int i = 2;i<n+1;i++){
            ans = curr + prev;
            prev = curr;
            curr = ans;
        }
        return ans;
    }
    int fib(int n) {
        //Create DP array :
        vector<int>dp(n+1,-1);
        int ans = solveUsingStorageOptimization(n);
        return ans;
    }
};
int main() {
    Solution sol;

    // Test cases
    std::cout << "Recursive: " << sol.fib(5) << endl;
    std::cout << "Memoisation: " << sol.fib(5) << endl;
    std::cout << "Tabularisation: " << sol.solveUsingStorageOptimization(5) << std::endl;
    std::cout << "Storage Optimization: " << sol.solveUsingStorageOptimization(5) << std::endl;

    return 0;
}