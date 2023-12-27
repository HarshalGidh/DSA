#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int s =0;
        int e= x;
        double mid = s + (e-s)/2;
        int ans = -1;
        //Search Space is between 0 to x:
        // Predicate Function will check the square of root x (mid)
        // Finding the Root x in the search space :
        while(s<=e){
            if(mid * mid == x){
                return mid;
            }
            else if(mid * mid < x){
                //Store the ans
                ans =  mid;
                s = mid +1;
            }
            else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}