#include <iostream>
using namespace std;
#include<stack>
#include<queue>
#include<deque>
#include<string>
class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> q;
        int freq[26] = {0};  // Initialize array with zeros
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch - 'a']++; //storing the int value of ch in that index for 'a' = 0 and 
            //increameneting it after each  encounter
            q.push(ch); //storing it inside Dequeue for ans
        }

        // answer nikalo
        while (!q.empty()) {
            char firstCharacter = q.front(); 
            if (freq[firstCharacter - 'a'] > 1) { //chcecking if firstCharacter was repeated 
                // more than once
                q.pop();
            } else {
                // == 1 or occured only once
                // return ans
                return s.find(firstCharacter); //returns index of that char
            }
        }

        return -1; // No unique character found so -1 returned
    }
};
int main() {
  Solution sol;
  string s = "leetcode";
  cout<<"Ans is : "<<sol.firstUniqChar(s);
  return 0;
}
// Example 1:

// Input: s = "leetcode"
// Output: 0

// Example 2:

// Input: s = "loveleetcode"
// Output: 2

// Example 3:

// Input: s = "aabb"
// Output: -1