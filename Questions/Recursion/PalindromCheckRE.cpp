#include <iostream>
using namespace std;
bool PalindromeCheckRE(string &s ,int start,int end){
  //BaseCase
  if(start >= end){
    return true;
  }
  //Processing 1 case
  if(s[start] != s[end]){ 
    return false;  //not a palindrome
  }

  return PalindromeCheckRE(s,start + 1 ,end -1) ; //checking for palindrome
}
int main() {
  string s = "racecar" ;
  int start = 0 ;
  int end = s.size() -1 ;
  bool Palindrome  = PalindromeCheckRE(s,start,end) ;
  if(Palindrome){
    cout << "Is A PALINDROME!" << endl;
  }
  else{
    cout << "Is NOT A PALINDROME!" << endl;
  }
 
  
  return 0;
}