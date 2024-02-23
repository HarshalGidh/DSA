#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,int limit){
        //Base Case :
        if(i >= prices.size()) return 0;
        if(limit == 0) return 0;
        int profit = 0;
        //Buy stock :
        if(buy){
            int buyProfit = -prices[i] + solve(prices,i+1,0,limit); //Considering buy Price as negative
            int skipProfit = solve(prices,i+1,1,limit); //skip buying today
            profit = max(buyProfit,skipProfit);
        }
        //Sell Stock :
        else{//Decreament limit by 1 as while selling a transaction pair is completed
            int sellProfit = prices[i] + solve(prices,i+1,1,limit-1) ;//sell stock and add it in profit
            int skipProfit = solve(prices,i+1,0,limit); //dont sell dont decrement limit here as no sell
            profit = max(sellProfit,skipProfit);
        }
        return profit;
    }
    int solveTD(vector<int>& prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp){
        //Base Case :
        if(i >= prices.size() || limit == 0) return 0;
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit] ;
        int profit = 0;
        //Buy stock :
        if(buy){
            int buyProfit = -prices[i] + solveTD(prices,i+1,0,limit,dp); //Considering buy Price as negative
            int skipProfit = solveTD(prices,i+1,1,limit,dp); //skip buying today
            profit = max(buyProfit,skipProfit);
        }
        //Sell Stock :
        else{//Decreament limit by 1 as while selling a transaction pair is completed
            int sellProfit = prices[i] + solveTD(prices,i+1,1,limit-1,dp) ;//sell stock and add it in profit
            int skipProfit = solveTD(prices,i+1,0,limit,dp); //dont sell dont decrement limit here as no sell
            profit = max(sellProfit,skipProfit);
        }
        dp[i][buy][limit] = profit;
        print(dp);
        return dp[i][buy][limit] ;
    }
     int solveBU(vector<int>& prices,vector<vector<vector<int>>>&dp){
         for(int i = prices.size() -1;i >= 0; i--){
            for(int buy = 0;buy < 2; buy++){
                for(int limit = 1;limit < 3; limit++){//limit 0 is already entered with 0 in dp
                    int profit = 0;
                    //Buy stock :
                    if(buy){
                        int buyProfit = -prices[i] + dp[i+1][0][limit]; //Considering buy Price as negative
                        int skipProfit = dp[i+1][1][limit]; //skip buying today
                        profit = max(buyProfit,skipProfit);
                    }
                    //Sell Stock :
                    else{//Decreament limit by 1 as while selling a transaction pair is completed
                        int sellProfit = prices[i] + dp[i+1][1][limit-1] ;//sell stock and add it in profit
                        int skipProfit = dp[i+1][0][limit]; //dont sell dont decrement limit here as no sell
                        profit = max(sellProfit,skipProfit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
            
         }
        print(dp);
        return dp[0][1][2] ;
    }
    int solveSO(vector<int>& prices,vector<vector<vector<int>>>&dp){
         for(int i = prices.size() -1;i >= 0; i--){
            for(int buy = 0;buy < 2; buy++){
                for(int limit = 1;limit < 3; limit++){//limit 0 is already entered with 0 in dp
                    int profit = 0;
                    //Buy stock :
                    if(buy){
                        int buyProfit = -prices[i] + dp[1][0][limit]; //Considering buy Price as negative
                        int skipProfit = dp[1][1][limit]; //skip buying today
                        profit = max(buyProfit,skipProfit);
                    }
                    //Sell Stock :
                    else{//Decreament limit by 1 as while selling a transaction pair is completed
                        int sellProfit = prices[i] + dp[1][1][limit-1] ;//sell stock and add it in profit
                        int skipProfit = dp[1][0][limit]; //dont sell dont decrement limit here as no sell
                        profit = max(sellProfit,skipProfit);
                    }
                    dp[0][buy][limit] = profit;
                }
            }
            //Shifting rows :
            dp[1] = dp[0] ;
         }
         print(dp);
         cout<<"Answer is : "<<dp[0][1][2]<<" at : [0][1][2] ";
        return dp[0][1][2] ;
    }
    void print(vector<vector<vector<int>>>&dp){
        cout<<"Printing DP array :"<<endl;
        for(int i = 0; i< dp.size();i++){
            cout<<i<<" :  "<<" 0 "<<"1 "<<"2 "<<endl;
            for(int j = 0; j< dp[0].size();j++){
                cout<<i<<" "<<j<<" : ";
                for(int k = 0; k < dp[0][0].size();k++){
                    cout<<dp[i][j][k]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
    int maxProfit(vector<int>& prices) {
        int limit = 2;
        // return solve(prices,0,true,limit);

        //Create 3d dp :
        // vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1))) ;
        // return solveTD(prices,0,true,limit,dp) ;

        //Create 3d dp :
        // vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0))) ;
        // return solveBU(prices,dp) ;

        //Create 3d dp :
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2,vector<int>(3,0))) ;
        return solveSO(prices,dp) ;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Max profit: " << sol.maxProfit(prices) << endl;

    return 0;
}
