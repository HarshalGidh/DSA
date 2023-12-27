#include <iostream>
using namespace std;
class Solution {
public:
    //Iterative Method :
    // string removeOccurrences(string s, string part) {
    //     while(s.find(part) != string::npos){
    //         //Find Part in string if found then remove it, else continue
    //         s.erase(s.find(part),part.length());
    //     }
    //     return s;
    // }
    //Recursion Method :
    void removeOCCRE(string &s,string &part){
        int found = s.find(part) ; //returns index where part was found
        if(found != string::npos){//part found in string s
            //Removing Part from string by making left part and right part of strings
            //which do not contain the subarray "Part"
            string left_part = s.substr(0,found); //substr makes substring from start index
            //till end index mentioned. Our Left part doesnt have string "part"
            string right_part = s.substr(found + part.size(),s.size());
            //taking right part from start of found index + size of "part"
            //till size of string s, we can also pass INT_MAX substr will find till \0
            s = left_part + right_part ; //removing 'part' by concatenating strings where
            //part is not present

            //baki recursion sambhal lega :
            removeOCCRE(s,part) ; //Recursion Call 
        }
        else{
            //Base Case
            return ;
        }
    }
     string removeOccurrences(string s, string part) {
        removeOCCRE(s , part) ;
        return s;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}