#include<iostream>
using namespace std;

class Nstack{
    //creating our 3 arays:
    int *a; //this is our main arreay where we will store our elements oif stack
    int *top; //this indicates the top element of a stack Sm, its size is n
    int *next; //this stores the next freeSpot in the main array and also the next element after top element of stack Sm
    int freeSpot; //this shows free spot in array
    int n; //number of stacks in array to be implememted, it is also the size of top array
    int size; //defined by user this is the size of thge main array and the size of next array
    public:
        Nstack(int _n,int _s):n(_n),size(_s){
            freeSpot = 0;
            a = new int[size];
            top = new int[n];
            next = new int[size];

            for(int i =0;i<n;i++){
                top[i] = -1 ; //-1 indicates stack is empty as its top element is -1
            }
            for(int i =0;i<size;i++){
                next[i] = i + 1;
            }
            next[size-1] = -1 ; //last element has no next freespot available in the main array

        }
        //Push x in mth stack Sm
        bool push(int x,int m){
            if(freeSpot == -1){
                cout<<"Stack Overflow !"<<endl;
                return false;
            }
            // 1. Find Index :
            int index = freeSpot ;
            // 2. Update FreeSpot :
            freeSpot = next[index];
            // 3. insert element in the mai array :
            a[index] = x ;
            //4. update next array:
            next[index] = top[m - 1];
            // 5. update top array :
            top[m-1] = index ;
            return true;
        }
        // pop from mth stack Sm
        int pop(int m){
            if(top[m-1] == -1){ //stack is empty
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            // 1. initialise index
            int index = top[m-1] ;
            // 2. update top :
            top[m-1] = next[index] ;    
            // 3. popped element 
            int poppedElement = a[index] ;
            // 4. update next :
            next[index] = freeSpot ;
            // 5. update freeSpot :
            freeSpot = index ;
            return poppedElement ;
        }
        ~Nstack(){
            //calling destructor
            delete[] a;
            delete[] top;
            delete[] next ;
        }
};
int main(){
    Nstack st(3,6) ;
    cout<<st.push(5,1)<<endl ;
    cout<<st.pop(1)<<endl;
    return 0;
}