#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
   int solve(vector<int>& prices,int i,int buy){
        //Base Case :
        if(i >= prices.size()) return 0;
        int profit = 0;
        //Buy stock :
        if(buy){
            int buyProfit = -prices[i] + solve(prices,i+1,0); //Considering buy Price as negative
            int skipProfit = solve(prices,i+1,1); //skip buying today
            profit = max(buyProfit,skipProfit);
        }
        //Sell Stock :
        else{
            int sellProfit = prices[i] + solve(prices,i+1,1) ;//sell stock and add igt in profit
            int skipProfit = solve(prices,i+1,0); //dont sell 
            profit = max(sellProfit,skipProfit);
        }
        return profit;
    }
    int solveTD(vector<int>& prices,int i,int buy,vector<vector<int>>&dp){
        //Base Case :
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        //Buy stock :
        if(buy){
            int buyProfit = -prices[i] + solveTD(prices,i+1,0,dp); //Considering buy Price as negative
            int skipProfit = solveTD(prices,i+1,1,dp); //skip buying today
            profit = max(buyProfit,skipProfit);
        }
        //Sell Stock :
        else{
            int sellProfit = prices[i] + solveTD(prices,i+1,1,dp) ;//sell stock and add igt in profit
            int skipProfit = solveTD(prices,i+1,0,dp); //dont sell 
            profit = max(sellProfit,skipProfit);
        }
        dp[i][buy] = profit;
        print(dp);
        return dp[i][buy];
    }
    void print(vector<vector<int>>&dp){
        cout<<"Printing DP array :"<<endl;
        for(int i = 0; i< dp.size();i++){
            cout<<i<<" : ";
            for(int j = 0; j< dp[0].size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
     int solveBU(vector<int>& prices,vector<vector<int>>&dp){
        //Base Case :
        for(int i = prices.size() -1 ;i >=0 ;i--){
            for(int buy = 0;buy < 2;buy++){
                int profit = 0;
                //Buy stock :
                if(buy){
                    int buyProfit = -prices[i] + dp[i+1][0]; //Considering buy Price as negative
                    int skipProfit = dp[i+1][1]; //skip buying today
                    profit = max(buyProfit,skipProfit);
                }
                //Sell Stock :
                else{
                    int sellProfit = prices[i] + dp[i+1][1] ;//sell stock and add igt in profit
                    int skipProfit = dp[i+1][0]; //dont sell 
                    profit = max(sellProfit,skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        print(dp);
        return dp[0][1] ;
    }
    int solveSO(vector<int>& prices,vector<vector<int>>&dp){
        //Base Case :
        for(int i = prices.size() -1 ;i >=0 ;i--){
            for(int buy = 0;buy < 2;buy++){
                int profit = 0;
                //Buy stock :
                if(buy){
                    int buyProfit = -prices[i] + dp[1][0]; //Considering buy Price as negative
                    int skipProfit = dp[1][1]; //skip buying today
                    profit = max(buyProfit,skipProfit);
                }
                //Sell Stock :
                else{
                    int sellProfit = prices[i] + dp[1][1] ;//sell stock and add igt in profit
                    int skipProfit = dp[1][0]; //dont sell 
                    profit = max(sellProfit,skipProfit);
                }
                dp[0][buy] = profit;
            }
            //shifting the row :
            dp[1] = dp[0] ;
            print(dp);
        }
        return dp[0][1] ;
    }
    int maxProfit(vector<int>& prices) {
        //return solve(prices,0,true);

        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return solveTD(prices,0,true,dp);

        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        // return solveBU(prices,dp);

        vector<vector<int>>dp(2,vector<int>(2,0)) ;
        return solveSO(prices,dp);
    }
};
   


int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max profit: " << sol.maxProfit(prices) << endl;

    return 0;
}
