#include <iostream>
#include<vector>
#include<string>
using namespace std;

void findSubsequence(string str,string output,int index){ //Function Defination
  //Base Case
  if(index >= str.length()){
    //exit the function or stop here
    cout<<"--> "<<output<<endl; //Printing Output String
    return;
  }
  //original order :
  //include character first
  char ch = str[index]; //storing current char in a variable
  output.push_back(ch);
  findSubsequence(str,output,index +1);//output has character included in it

  //exclude the character :
  output.pop_back(); //removing the inserted character 'ch'
  findSubsequence(str,output,index + 1); 

  // //(reverse order)
  // //exclude the character first
  // char ch = str[index] ; //storing current char in a variable
  // //Calling function to return excluded string
  // findSubsequence(str,output,index+1) ;//excluding the char and increamenting index by 1 

  // //include character in output
  // output.push_back(ch); //inserting ch in output string
  // //Calling Function to Include the char in output string
  // findSubsequence(str,output,index +1) ;//Now output has character included in it

}

int main() {
  string str = "abc"; //input string
  string output = ""; //output string
  int index = 0; //starting index
  findSubsequence(str ,output, index); //Function Call
  cout<<"Original String :"<<str;
  //cout << "Printing Output Vector :" << endl;
  return 0;
}