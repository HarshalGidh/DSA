#include <iostream>
using namespace std;
class Solution {
public:
    int solve(vector<int>& coins, int amount){
        if(amount == 0){
            return 0; //0 coins required for 0 amount
        }
        int mini = INT_MAX;
        int ans = INT_MAX;
        for(int i = 0 ;i < coins.size();i++){
            int coin = coins[i]; //taking a coin(ex 1,2) from coins
            if(coin <= amount){ //use coin when coin less than amount
                int recAns = solve(coins,amount - coin);
                if(recAns != INT_MAX){ //INT_MAX indicates invalid coin division
                    ans = 1 + recAns ; //one + reccursion answer
                }
                else{
                    return -1 ;
                }
            }
            mini = min(mini ,ans) ;
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins,amount);
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}