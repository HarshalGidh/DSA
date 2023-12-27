#include <iostream>
using namespace std;
class Solution {
public:
/*
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int i = 0;
        int j = col - 1;
        
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--; // Move left in the current row
            } else {
                i++; // Move down to the next row
            }
        }
        
        return false;
    }
};
*/  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row*col; // No. of elements in matrix

        int s = 0;
        int e = n-1;
        //int mid = s + (e-s)/2 ;

        while(s<=e){
            /*
                for 2d to 1d conversion : 
                mid = C*i + j where mid is current element 
                C is column,i is current row index and j is current column index

            */

            /*
                for 1d to 2d conversion i = mid/C and j = mid%C 
            */
            int mid = s + (e-s)/2 ;
            int rowIndex = mid/col;
            int colIndex = mid % col;
            int currNumber = matrix[rowIndex][colIndex] ;
            
            if(currNumber == target){
                return true;
            }
            else if(currNumber > target){
                //Go right
                s = mid +1;
            }
            else{
                //left
                e = mid - 1;
            }
            //mid = s + (e-s)/2;
        }
        return false;
    }
};

int main() {
  cout << "Hello world!" << endl;
  return 0;
}