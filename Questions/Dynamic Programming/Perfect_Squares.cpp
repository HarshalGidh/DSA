#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
class Solution {
public:
    int numSquaresHelper(int n) {
        //Base Case
        if (n == 0) return 1; //Possible Solution
        if (n < 0) return 0; //Invalid solution
        //1 Case Processing 
        int i = 1; //starting int as 1
        int end = sqrt(n); //to process sqrt(n) perfect squares
        int ans = INT_MAX; // we need minimum ans
        while (i <= end) {
            int PerfectSquares = i * i;
            int NumberOfPerfectSquares = 1 + numSquaresHelper(n - PerfectSquares); //RE Call
            //here we will calculate no of min PerfectSquares
            if (NumberOfPerfectSquares < ans) {
                ans = NumberOfPerfectSquares;
            }
            i++;
        }
        return ans;
    }

    //using Memoization : T.C: O(n)
    int numSquareMemo(int n, vector<int>& dp) {
        //Base Case :
        if (n == 0) return 1;
        if (n < 0) return 0; //no poss solution
        //if ans already stored return ans :
        if (dp[n] != -1) return dp[n];
        int end = sqrt(n);
        //run a loop for sqrt of n times :
        int ans = INT_MAX;
        int start = 1;
        while (start <= end) {
            int perfectSquare = start * start;
            int numberOfPerfectSquares = 1 + numSquareMemo(n - perfectSquare, dp);
            if (numberOfPerfectSquares < ans) ans = numberOfPerfectSquares;
            start++;
        }
        //store ans in dp[n]
        dp[n] = ans;
        return dp[n];
    }

    //using Tabulation : T.C :O(n)
    int numSquareUsingTabulation(int n) {
        //Create DP array :
        std::vector<int> dp(n + 1, -1);
        //Analyse the Base Case and fill some elememnts of dp array :
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int end = sqrt(i);
            int start = 1;
            int ans = INT_MAX;
            while (start <= end) {
                int perfectSquare = start * start;
                int numberOfPerfectSquares = 1 + dp[i - perfectSquare];
                if (numberOfPerfectSquares < ans) ans = numberOfPerfectSquares;
                start++;
            }
            //store ans in dp :
            dp[i] = ans;
        }
        return dp[n];
    }

    int numSquares(int n) {
        //return numSquaresHelper(n) - 1; // subtracting 1 as there are n+1 RE Calls
        //Create DP array :
        //std::vector<int> dp(n + 1, -1);
        //int ans = numSquareMemo(n, dp) - 1;
        int ans = numSquareUsingTabulation(n) - 1;
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    int result1 = sol.numSquares(12);
    cout << "Example 1: " << result1 << endl;

    // Example 2
    int result2 = sol.numSquares(13);
    cout << "Example 2: " << result2 << endl;

    return 0;
}
