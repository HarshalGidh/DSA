#include <iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    //Recursion method
    // void maxProfitFinder(vector<int>& prices,int i,int &minprice,int &maxprofit){
    //     //Base Case 
    //     if(i == prices.size()){
    //         return;
    //     }
    //     //Ek case handle karo
    //     if(prices[i] < minprice){
    //         minprice = prices[i];
    //     }
    //     int todaysPrice = prices[i] - minprice ;
    //     if(todaysPrice > maxprofit){
    //         maxprofit = todaysPrice ;
    //     }
    //     //Recursion Call
    //     maxProfitFinder(prices,i + 1,minprice,maxprofit);

    // }
    // int maxProfit(vector<int>& prices) {
    //     int minprice = INT_MAX;
    //     int maxprofit = INT_MIN;
    //     maxProfitFinder(prices,0,minprice,maxprofit);
    //     return maxprofit;

    //Iterative Method :
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = INT_MIN;
        for(int i =0;i<prices.size();i++){
            minprice = min(prices[i],minprice);
            maxprofit = max(prices[i] - minprice,maxprofit) ;
        }
        return maxprofit;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}