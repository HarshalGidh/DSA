#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0; // 0 coins required for 0 amount
        }
        if (amount < 0) {
            return INT_MAX;
        }
        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i]; // taking a coin(ex 1,2) from coins
            if (coin <= amount) { // use coin when coin less than amount
                int recAns = solve(coins, amount - coin);
                if (recAns != INT_MAX) { // INT_MAX indicates invalid coin division
                    int ans = 1 + recAns; // one + reccursion answer
                    mini = min(mini, ans);
                }
                else {
                    return -1;
                }
            }
        }
        return mini;
    }

    // using Top-Down method :
    int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp) {
        // Base Case :
        if (amount == 0) return 0;
        // if ans stored return ans :
        if (dp[amount] != -1) return dp[amount];
        // explore all paths :
        int ans;
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                int recAns = solveUsingMem(coins, amount - coins[i], dp);
                if (recAns != INT_MAX) {
                    ans = 1 + recAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    // using Bottom Up :
    int solveUsingTabulation(vector<int>& coins, int& amount) {
        int n = amount;
        // create dp array :
        vector<int> dp(n + 1, -1);
        // Analyse Base Case and fill dp array :
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int mini = INT_MAX;
            int ans;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    int recAns = dp[i - coins[j]];
                    if (recAns != INT_MAX) {
                        ans = 1 + recAns;
                        mini = min(mini, ans);
                    }
                }
            }
            dp[i] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // int ans = solve(coins,amount);
        // int n = amount;
        // create dp array :
        // vector<int>dp(n+1,-1);
        // int ans = solveUsingMem(coins,amount,dp);
        int ans = solveUsingTabulation(coins, amount);
        if (ans == INT_MAX) {
            return -1;
        }
        else {
            return ans;
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    int result1 = sol.coinChange(coins1, amount1);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    int result2 = sol.coinChange(coins2, amount2);
    cout << "Example 2: " << result2 << endl;

    // Example 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    int result3 = sol.coinChange(coins3, amount3);
    cout << "Example 3: " << result3 << endl;

    return 0;
}



// class Solution {
// public:
//     int solve(vector<int>& coins, int amount){
//         if(amount == 0){
//             return 0; //0 coins required for 0 amount
//         }
//         if(amount <0){
//             return INT_MAX ;
//         }
//         int mini = INT_MAX;
        
//         for(int i = 0 ;i < coins.size();i++){
//             int coin = coins[i]; //taking a coin(ex 1,2) from coins
//             if(coin <= amount){ //use coin when coin less than amount
//                 int recAns = solve(coins,amount - coin);
//                 if(recAns != INT_MAX){ //INT_MAX indicates invalid coin division
//                     int ans = 1 + recAns ; //one + reccursion answer
//                      mini = min(mini ,ans) ;
//                 }
//                 else{
//                     return -1 ;
//                 }
//             }
//         }
//         return mini;
//     }
// //using Top-Down method :
//     int solveUsingMem(vector<int>& coins, int amount,vector<int>&dp){
//         //Base Case :
//         if(amount == 0) return 0;
//         //if ans stored return ans :
//         if(dp[amount] != -1) return dp[amount] ;
//         //explore all paths :
//         int ans;
//         int mini = INT_MAX;
//         for(int i = 0 ; i< coins.size();i++){
//             if(amount - coins[i] >= 0){
//                 int recAns = solveUsingMem(coins,amount - coins[i],dp);
//                 if(recAns != INT_MAX){
//                     ans = 1 + recAns ;
//                     mini = min(mini,ans);
//                 }
//             }
//         }
//         dp[amount] = mini;
//         return dp[amount] ;
//     }
// //using Bottom Up :
//     int solveUsingTabulation(vector<int>& coins, int &amount){
//         int n = amount;
//         //create dp array :
//         vector<int>dp(n+1,-1);
//         //Analyse Base Case and fill dp array :
//         dp[0] = 0;
//         for(int i = 1;i<=amount;i++){
//             int mini = INT_MAX;
//             int ans;
//             for(int j = 0;j < coins.size();j++){
//                 if(i - coins[j] >= 0){
//                     int recAns = dp[i - coins[j]];
//                     if(recAns != INT_MAX){
//                         ans = 1 + recAns ;
//                         mini = min(mini,ans);
//                     }
//                 }
//             }
//             dp[i] = mini;
//         }
//         return dp[amount] ;
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         //int ans = solve(coins,amount);

//         //int n = amount;
//         //create dp array :
//         // vector<int>dp(n+1,-1);
//         // int ans = solveUsingMem(coins,amount,dp);
//         int ans  =  solveUsingTabulation(coins,amount);
//         if(ans == INT_MAX){
//             return -1;
//         }
//         else{
//             return ans;
//         }
//     }
// };
