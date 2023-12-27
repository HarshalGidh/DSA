#include <iostream>
using namespace std;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        //Base Case
        if(target <0) return 0; //target became negative
        if(n!=0 && target == 0) return 0;//all dice not used but sum achieved
        if(n==0 && target !=0) return 0;// sum not achived but all dice thrown
        if(n==0 && target == 0) return 1 ;//all conditions met
        //Processing 1 case baki recursion
        int ans = 0;
        for(int i =1 ;i<=k;i++){ //to iterate all dice values
            ans = ans + numRollsToTarget(n-1,k,target -i);
        }
        return ans;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}