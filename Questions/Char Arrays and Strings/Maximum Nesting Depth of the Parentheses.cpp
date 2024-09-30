#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        for(char c:s){
            if(c == '(' ){ // Count opening brackets
                count++;
            }
            ans = max(ans, count);
            if(c == ')' ){ // Expression ended, remove open brackets
                count--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    string s1 = "(1+(2*3)+((8)/4))+1";
    string s2 = "(1)+((2))+(((3)))";
    
    // Output the results
    cout << "Output for s1: " << sol.maxDepth(s1) << endl; // Output: 3
    cout << "Output for s2: " << sol.maxDepth(s2) << endl; // Output: 3
    
    return 0;
}

// Python Code :
// class Solution:
//     def maxDepth(self, s: str) -> int:
//         count = 0
//         max_depth = 0
//         for char in s:
//             if char == '(':
//                 count += 1
//             max_depth = max(count, max_depth)
//             if char == ')':
//                 count -= 1
//         return max_depth