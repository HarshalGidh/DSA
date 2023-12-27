#include <iostream>
using namespace std;
void reverseString(string& s,int i,int e,int n){
  //Base Case 
  if(i >= e){ //if i >= e then string is reversed 
    return ;
  }
  //Processing 1 case :
  swap(s[i] , s[e]) ;
  //Recursive Call :
  reverseString(s,i+1,e-1,n) ;
}
int main() {
  string s ;
  cout << "Enter a String :" << endl;
  cin >>s ;
  cout<<"Before Reversing :"<<s<<endl;
  int n = s.size() ; //lenghth of string
  int i = 0; //index
  int e = n-1 ; //end index
  reverseString(s,i,e,n);
  cout<<"After Reversing String :"<<s ;
  return 0;
}