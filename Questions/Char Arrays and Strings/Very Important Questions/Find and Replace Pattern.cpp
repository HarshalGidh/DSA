#include <iostream>
using namespace std;
class Solution {
public:
    void createMapping(string& str){
        //this function normalises all the words and pattern into a similar format
        //then transforms them into the similar pattern so that we can compare them
        //and find the solution

        char start ='a';//start char
        char mapping[300] = {0}; //creating mapping char arr

        for(auto ch : str){
            //mapping the characters
            if(mapping[ch] == 0){
                mapping[ch] = start;
                start++;
            }
        }
        //Normalising the string for comparison :
        // for(auto ch : str){
        //     str[ch] = mapping[ch];
        // }
        for(int i = 0; i<str.length();i++){
            char ch = str[i];
            str[i] = mapping[ch];
        }

    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans; //our ans string
        //Normalising the pattern :
        createMapping(pattern); //returns normalised pattern

        //running a for loop to traverse "words"  
        for(string s : words){
            string tempString = s;//creating a tempstring so that our ans string is not lost
            createMapping(tempString);//tranforming string for comparison
            if(tempString == pattern){
                ans.push_back(s);
            }
        }
        return ans;

    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}