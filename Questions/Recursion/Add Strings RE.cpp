#include <iostream>
using namespace std;
class Solution {
public:
    void addRE(string& num1, int p1, string& num2, int p2, int carry, string& ans) {
        // Base Case
        if (p1 < 0 && p2 < 0) { // When both num strings are traversed
            if (carry != 0) {
                ans.push_back(carry + '0'); // Adding additional carry to ans
            }
            return;
        }
        // Processing for each case:
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0'; // If p1 < 0, num1 is exhausted, so take '0'
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry;  // Sum of 2 digits
        int digit = csum % 10; // Extracting the sum's digit
        carry = csum / 10; // Carry is extracted
        ans.push_back(digit + '0'); // Pushing digit into ans by string formatting
        // Rest will be handled by recursion
        addRE(num1, p1 - 1, num2, p2 - 1, carry, ans); // Reducing the pointers
    }

    string addStrings(string num1, string num2) {
        string ans = ""; // Creating an answer string
        addRE(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans); // Carry = 0
        reverse(ans.begin(), ans.end()); // Reversing the string as ans has reverse addition result
        return ans;
    }
};

int main() {
  cout << "Hello world!" << endl;
  return 0;
}