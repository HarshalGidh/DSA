#include<iostream>
#include<stack>
#include<utility>
#include<vector>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1; //every stock will have min span as 1
        while(!st.empty() && st.top().first <= price ){
            span += st.top().second ;//adding span of the other stocks
            st.pop();
        }
        st.push({price,span});//pushing the stock in the stack
        return st.top().second;//span ;
    }
};
int main(){
    StockSpanner stock;
    cout<<"Span : "<<stock.next(7)<<endl;
    cout<<"Span : "<<stock.next(2)<<endl;
    cout<<"Span : "<<stock.next(1)<<endl;
    cout<<"Span : "<<stock.next(2)<<endl;
    return 0;
}
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */