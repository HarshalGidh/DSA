#include <iostream>
using namespace std;
//Very Important !!!!!!
//T.C = O(n^2) and space complexity = O(1)
class Solution {
public:
    int expand(string s,int i ,int j){
        // to check palindrome and palindrome substrings
        //initialising count for odd r even substring
        int count = 0;
        while(i>=0 && j<s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        //We will find substrings by using 2 pointers at an element and then check 
        //palindrome substrings by moving the 2 pointers in opposite direction to traverse
        //the string in n/2 steps and checking for palindrome substrings.
        //a substring can be odd length or even in length adding both will give us all 
        //possible palindrome substrings
        //We have created a totalcount which will be even + odd substring
        int totalCount = 0;
        //To count total susbstrings elements:
        for(int center = 0;center < s.length();center++){
            //Odd substring(1 ch,3ch,...)
            //sending the string, for odd the two pointers will be same
            // initially and then expand it outwards in opposite direction

            int odd_count = expand(s,center,center);

            //Even susbtring(2ch,4ch,...)
            //sending the string s,for even the 2 pointers wont be same
            //hence i will be center and j center+1

            int even_count = expand(s,center,center + 1);

            //now adding total count after one iteration
            totalCount = totalCount + odd_count + even_count ; 
        }
        return totalCount ;
    }
};

int main() {
//decsription:Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

//   Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
  return 0;
}