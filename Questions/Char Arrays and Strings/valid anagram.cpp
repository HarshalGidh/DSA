#include <iostream>
using namespace std;
//valid anagram
class Solution { //my method : Sorting
public:
    bool isAnagram(string s, string t) {
        if(s.length() == t.length()){ //if length is same cont else false
            sort(s.begin(),s.end()); //sorting s string
            sort(t.begin(),t.end()); //sorting t string
            for(int i = 0;i<s.length();i++){ //traversing s
                if(s[i] != t[i]){
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
};
class Solution { //count merhod
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int freqTable[256] = {0}; //creating a Hash Table or Frequency Table
        for(int i = 0;i<s.size();i++){//counting every char by mapping
            freqTable[s[i]]++; //adding count for a char
        } 
        for(int j = 0;j<t.size();j++){
            freqTable[t[j]]--; //minusing every occurence of same char
        }
        //checking if freqTable is equal to 0,if yes then anagram else not
        for(int i =0;i<256;i++){
            if(freqTable[i] != 0){
                return false;
            }
        }
        return true;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}