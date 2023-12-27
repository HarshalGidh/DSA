#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        // For 90 degrees(clockwise shift) transpose the matrix then reverse it
        //Transpose
        for(int i = 0;i<n; i++){
            for(int j = i;j<matrix[i].size();j++){
                // j = i to access upper triangle only and swapping them
                // when i = j it will swap with itself hence it wont get changed
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Reverse all rows of 2d matrix
        //No.of rows are from r = 0 to n-1
        for(int i = 0; i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}