#include <iostream>
using namespace std;
#include<limits.h>
#include<math.h>
class Solution {
public:
    int numSquaresHelper(int n){
        //Base Case
        if(n == 0) return 1 ; //Possible Solution
        if(n < 0) return 0 ; //Invalid solution
        //1 Case Processing 
        int i = 1; //starting int as 1
        int end= sqrt(n); //to process sqrt(n) perfect squares
        int ans = INT_MAX ; // we need minimum ans
        while(i <= end){
            int PerfectSquares = i*i ;
            int NumberOfPerfectSquares = 1 + numSquaresHelper(n - PerfectSquares); //RE Call
            //here we will calculate no of min PerfectSquares
            if(NumberOfPerfectSquares < ans){
                ans = NumberOfPerfectSquares ; 
            }
            i++ ;
        }
        return ans ; 
    }
    int numSquares(int n) {
        return numSquaresHelper(n) - 1; // subtracting 1 as there are n+1 RE Calls
    }
};
int main() {
  cout << "Hello world!" << endl;
  Solution s;
  int ans = s.numSquares(12);
  cout<<"Answer is :"<<ans ;
  return 0;
}
//Description
// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
//Test Cases
// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 

// Constraints:

// 1 <= n <= 104