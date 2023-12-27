#include <iostream>
#include <vector>
using namespace std;

int Num(vector<int>& digit, int &num,int size, int index) {
    
    // Base Condition
    if (index >= size) {
        return num/10;
    }
    num = num + digit[index];
    num = num*10;
    return Num(digit,num,size,index+1);
   
}

int main() {
    vector<int> digit = {4,2,8,1,4};
    int size = digit.size();
    int index = 0;
    int num = 0;
    num = Num(digit, num,size, index);
    cout << num ;
   
    
    return 0;
}
