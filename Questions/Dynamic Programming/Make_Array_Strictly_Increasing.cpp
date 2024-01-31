#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    #define INF (1e9 + 1) 
    int solveUsingRec(vector<int>& arr1, vector<int>& arr2, int prev, int i) {
        // Base Case :
        if (i == arr1.size()) return 0;
        int opt1 = INF;
        if (prev < arr1[i]) {
            opt1 = solveUsingRec(arr1, arr2, arr1[i], i + 1);
        }
        // trying all possibilities:
        int opt2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end()) {
            int index = it - arr2.begin();
            opt2 = 1 + solveUsingRec(arr1, arr2, arr2[index], i + 1);
        }
        return min(opt1, opt2);
    }

    int solveUsingTD(vector<int>& arr1, vector<int>& arr2, int prev, int i, map<pair<int, int>, int>& dp) {
        // Base Case :
        if (i == arr1.size()) return 0;
        if (dp.find({prev, i}) != dp.end()) return dp[{prev, i}];
        int opt1 = INF;
        if (prev < arr1[i]) {
            opt1 = solveUsingTD(arr1, arr2, arr1[i], i + 1, dp);
        }
        // trying all possibilities:
        int opt2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end()) {
            int index = it - arr2.begin();
            opt2 = 1 + solveUsingTD(arr1, arr2, arr2[index], i + 1, dp);
        }
        return dp[{prev, i}] = min(opt1, opt2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        // int ans = solveUsingRec(arr1, arr2, -1, 0);

        // create map :
        map<pair<int, int>, int> dp;
        int ans = solveUsingTD(arr1, arr2, -1, 0, dp);
        if (ans == INF) return -1;
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1:
    vector<int> arr1_1 = {1, 5, 3, 6, 7};
    vector<int> arr2_1 = {1, 3, 2, 4};
    cout << "Example 1: " << sol.makeArrayIncreasing(arr1_1, arr2_1) << endl;

    // Example 2:
    vector<int> arr1_2 = {1, 5, 3, 6, 7};
    vector<int> arr2_2 = {4, 3, 1};
    cout << "Example 2: " << sol.makeArrayIncreasing(arr1_2, arr2_2) << endl;

    // Example 3:
    vector<int> arr1_3 = {1, 5, 3, 6, 7};
    vector<int> arr2_3 = {1, 6, 3, 3};
    cout << "Example 3: " << sol.makeArrayIncreasing(arr1_3, arr2_3) << endl;

    return 0;
}
