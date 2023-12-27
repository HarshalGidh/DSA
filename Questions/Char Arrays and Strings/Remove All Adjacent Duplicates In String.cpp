#include <iostream>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int index = 0;

        while(index < s.length()){
            //check if rightmost element of the ans is same as the current element in the  /            /string , if same then pop the ch from ans
            if(ans.length() > 0 && ans[ans.length() - 1] == s[index]){
                //pop ans 
                ans.pop_back();
            }   
            else{
                //rightmost and current element are not same so push it in ans
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
    }
};

int main() {
//   Input: s = "abbaca"
// Output: "ca"
  return 0;
}