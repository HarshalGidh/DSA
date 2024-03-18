#include <iostream>
#include <algorithm>

using namespace std;

// Definition of the Item struct
struct Item {
    int value;
    int weight;
};

// Definition of the Solution class
class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr , arr+ n ,[](const auto &a , const auto &b){
            double x = static_cast<double>(a.value) / a.weight;
            double y = static_cast<double>(b.value) / b.weight;
            return  x > y;
        });
        
        double ans = 0.0; int i = 0;
        while(W > 0 && i < n){
            if(arr[i].weight <= W){
                W -= arr[i].weight;
                ans+= arr[i].value;
            }
            else{
                ans += (static_cast<double>(arr[i].value)/arr[i].weight)*W;
                W= 0;
            }
            i++;
        }
        return ans;
    }  
};

// Main function
int main() {
    int n, W;
    cin >> n >> W;

    // Creating an array of items
    Item arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].value >> arr[i].weight;
    }

    // Creating an object of Solution class
    Solution sol;

    // Calling the fractionalKnapsack function and printing the result
    cout << sol.fractionalKnapsack(W, arr, n) << endl;

    return 0;
}
