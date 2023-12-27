#include <iostream>
using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            //Find Part in string if found then remove it, else continue
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};
int main() {
//   Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
  return 0;
}