#include <iostream>
using namespace std;
void lastOccurence(string s ,char x ,int i, int& ans){
  // BASE Case
  if(i >= s.size()){
    return ;
  }
  //One Case to handle 
  if(s[i] == x){
    ans = i ;
  }
  //Recursion Call
  lastOccurence(s,x,i+1,ans) ;
}
int main() {
  string s; //input string
  cout<<"Enter String :";
  cin>> s;
  cout<<"Enter Character :";
  char x;
  cin >> x; // target character
  int ans = -1 ;
  int i = 0;
  lastOccurence(s , x ,i ,ans) ;
  cout <<ans <<endl;
  return 0;
}