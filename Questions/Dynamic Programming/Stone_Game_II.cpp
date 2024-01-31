#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(vector<int>& piles,int i,int M,int aliceTurn){
        //Base Case :
        if(i == piles.size() ) return 0;
        int ans = aliceTurn ? INT_MIN : INT_MAX; //if its Alice's turn we want max ans and for Bob
        //Min ans 
        //Explore all possible ways :
        int total = 0;
        for(int X = 1;X <= 2*M ;X++){
            if(i + X - 1 > piles.size() ) break ; //out of bound
            total += piles[i + X - 1] ; //to get x+i-1 piles
            if(aliceTurn) //maximize Alice Ans :
                ans = max(ans, total + solveUsingRecursion(piles,i+X,max(X,M),!aliceTurn) ) ;
            else
                ans = min(ans,solveUsingRecursion(piles,i+X,max(X,M),!aliceTurn) ) ;
        }
        return ans;
    }
    int solveUsingMem(vector<int>& piles,int i,int M,int aliceTurn,vector<vector<vector<int>>>&dp){
        //Base Case :
        if(i == piles.size() ) return 0;
        if(dp[i][M][aliceTurn] != -1) return dp[i][M][aliceTurn] ;
        int ans = aliceTurn ? INT_MIN : INT_MAX; //if its Alice's turn we want max ans and for Bob
        //Min ans 
        //Explore all possible ways :
        int total = 0;
        for(int X = 1;X <= 2*M ;X++){
            if(i + X - 1 >= piles.size() ) break ; //out of bound
            total += piles[i + X - 1] ; //to get x+i-1 piles
            if(aliceTurn) //maximize Alice Ans :
                ans = max(ans, total + solveUsingMem(piles,i+X,max(X,M),!aliceTurn,dp) ) ;
            else
                ans = min(ans,solveUsingMem(piles,i+X,max(X,M),!aliceTurn,dp) ) ;
        }
        return dp[i][M][aliceTurn] = ans;
    }
    int solveUsingTabulation(vector<int>& piles){
        //create 3d dp array :
        //initialize with 0 to handle Base Case 
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0))) ;
        //using Bottom Up Approach :
        for(int i = piles.size() - 1;i >= 0;i--){
            for(int M = piles.size() ;M >= 1; M--){
                for(int aliceTurn = 0; aliceTurn <= 1;aliceTurn++ ){
                    int ans = aliceTurn ? INT_MIN : INT_MAX; //if its Alice's turn we want max ans and for Bob
                    //Min ans 
                    //Explore all possible ways :
                    int total = 0;
                    for(int X = 1;X <= 2*M ;X++){
                        if(i + X - 1 >= piles.size() ) break ; //out of bound
                        total += piles[i + X - 1] ; //to get x+i-1 piles
                        if(aliceTurn) //maximize Alice Ans :
                            ans = max(ans, total + dp[i+X][max(X,M)][!aliceTurn]) ;
                        else
                            ans = min(ans, dp[i+X][max(X,M)][!aliceTurn]) ;
                    }
                    dp[i][M][aliceTurn] = ans;
                }
            }
        }
        return dp[0][1][1] ;
    }
    int stoneGameII(vector<int>& piles) {
        int i = 0,M=1, aliceTurn = 1; //aliceTurn tells if its Alice's turn or Bob's
        //return solveUsingRecursion(piles,i,M,aliceTurn);
        //create 3d dp array :
        // vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1))) ;
        // return solveUsingMem(piles,i,M,aliceTurn,dp) ;

        return solveUsingTabulation(piles) ;
    }
};
int main() {
    Solution sol;

    // Example 1
    vector<int> piles1 = {2, 7, 9, 4, 4};
    cout << "Example 1: " << sol.stoneGameII(piles1) << endl;

    // Example 2
    vector<int> piles2 = {1, 2, 3, 4, 5, 100};
    cout << "Example 2: " << sol.stoneGameII(piles2) << endl;

    return 0;
}
