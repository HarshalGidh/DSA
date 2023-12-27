#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatchHelper(string s,int si,string p,int pi){
        //base case
        if(si == s.size() && pi == p.size()){
            return true; //all char are matching
        }
        if(si == s.size() && pi < p.size()){
            while(pi < p.size()){
                if(p[pi] != '*'){ //if there are no '*' ahead then return false
                    return false;
                }
                pi++ ;
            }
            return true ; //all '*' taken care of 
        }
        //1 Case ka solving
        if(s[si] == p[pi] || p[pi]  == '?'){
            return isMatchHelper(s,si+1,p,pi+1);
        }
        if(p[pi] == '*'){
            //Two cases
            //case A treat '*' as ""(null character)
            bool caseA = isMatchHelper(s,si,p,pi+1); //skipping p as null
            //caseB treat "*" to consume 1 character
            bool caseB = isMatchHelper(s,si+1,p,pi) ; //going to next char of s
            return caseA ||caseB ;
        }
        return false; //no match found
    }
    bool isMatch(string s, string p) {
        int si = 0; //s i ka pointer
        int pi = 0 ; //pi ka pointer   
        return isMatchHelper(s , si , p , pi);
         
         }
};
int main() {
  cout << "Hello world!" << endl;
  Solution s ;
  bool ans = s.isMatch("aa","*") ;
  cout << "Result: " << (ans == 0 ? "false" : "true") << endl;
  return 0;
}
//Description :
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
// // Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

// Constraints:

// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.