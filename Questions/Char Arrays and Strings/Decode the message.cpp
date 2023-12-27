#include <iostream>
using namespace std;
class Solution {
public:
    string decodeMessage(string key, string message) {
        //Creating Mesage :
        char start = 'a';   // similar to int i =0
        char mapping[300] = {0}; //we created a char arr where in general 
        //the 256 characters(1 byte =8 bits therefore 2^8 characters) are there and 
        // we will map each char with another char. eg t of key is mapped with a
        //initialising it with 0 so that no character is unmapped initially

        for(auto ch : key){ //basically this traverses the key string and stores it to ch
            // this s equivalent to for(i=0;i<n;i++){char ch = key[i]}
            if(ch != ' ' && mapping[ch] == 0){ //if mapping already exists and if space then skip
                mapping[ch] = start ; //mapping ch to another char
                start++; // changing from a to b ...
            }
        }
        // using mapping 
        string ans; //creating new ans string
        for(auto ch : message){
            if(ch == ' '){
                ans.push_back(' ');
            }
            else{
                char decodeChar = mapping[ch]; //mapping['a'] would be decoded here
                ans.push_back(decodeChar);
            }
        }
        return ans ;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}