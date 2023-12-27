#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int n =mat.size();
        //OneCount wil store max no. of 1's
        int OneCount = INT_MIN;
        // row_no will store the row index of max 1's
        int row_no = -1;
        for(int i =0; i<n;i++){
            int count = 0;
            for(int j = 0; j<mat[i].size();j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            //Comparing row count with OneCount:
            if(count>OneCount){
                OneCount = count ; 
                row_no = i ;
            }
        }
        //Submitting the answer by pusing row_no and OneCount in ans vector
        ans.push_back(row_no);
        ans.push_back(OneCount);
        return ans;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}