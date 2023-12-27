#include <iostream>
using namespace std;
class Solution {
public:
    static string str;
    //custom comparator :
    static bool compare(char &ch1 , char &ch2){
        return (str.find(ch1) < str.find(ch2)) ;
    }
    string customSortString(string order, string s) {
        str = order;
        //Using Custom Comparator :
        sort(s.begin(),s.end(), compare);
        return s; //returning sorted string
    }
};
string Solution :: str ;
int main() {
  cout << "Hello world!" << endl;
  return 0;
}