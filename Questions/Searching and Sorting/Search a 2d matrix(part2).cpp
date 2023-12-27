#include <iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) return false; // Handle the case of an empty matrix
        int col = matrix[0].size();
        
        int left = 0;
        int right = row * col - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / col][mid % col];
            
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
//This code treats the 2D matrix as a flattened 1D array and performs a binary search on it. It adjusts the indices appropriately to access elements in the matrix. The time complexity of this code is O(log(m*n)), where m and n are the number of rows and columns in the matrix, respectively.
int main() {
  cout << "Hello world!" << endl;
  return 0;
}