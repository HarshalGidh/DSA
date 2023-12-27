#include <iostream>
using namespace std;
class Solution {
public:
    bool checkLetters(char &ch){
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <='Z'){ 
            return true;
    }
        else{
            return false;
        }
    }
    string reverseOnlyLetters(string s) {
        int start = 0;
        int end = s.size() -1;
        bool letter;
        while(start < end){ //for equal start and end swap makes no sense
            
            if(checkLetters(s[start]) && checkLetters(s[end]) ){//isalpha(s[ch]) wcould be
             //used as well instead of using conditions
                    swap(s[start],s[end]);
                    start++;
                    end--;
                }
                else if(checkLetters(s[start]) == false){
                    start++;
                }
                else{
                    end--;
                }
            }
        return s;
    }
};
int main() {
  cout << "Hello world!" << endl;
  return 0;
}