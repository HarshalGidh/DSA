#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& curr, vector<int>& prev) {
        // curr -> bade wala dabba
        // prev -> chootte wala dabba
        if (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]) {
            return true;
        } else {
            return false;
        }
    }

    int solveUsingTabulationSO(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr_index = n - 1; curr_index >= 0; curr_index--) {
            for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--) {
                int include = 0;
                if (prev_index == -1 || check(cuboids[curr_index], cuboids[prev_index])) {
                    int heightToAdd = cuboids[curr_index][2];
                    include = heightToAdd + nextRow[curr_index + 1];
                }
                int exclude = 0 + nextRow[prev_index + 1];
                currRow[prev_index + 1] = max(include, exclude);
            }
            // shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort the cuboid Dimensions such that height is the max dim
        // This will help us to place the max height by stacking cuboids:
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        // Now Sort the cuboids w.r.t. the first dim in asc order:
        // The last cuboid will have the max height
        sort(cuboids.begin(), cuboids.end());
        // Now we stack the cuboids one on top of another when the condition is satisfied
        // To do this we need to stack them in the increasing order of the subsequence
        int ans = solveUsingTabulationSO(cuboids);
        return ans;
    }
};

int main() {
    Solution solution;

    // Example 1:
    vector<vector<int>> cuboids1 = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    cout << "Example 1: " << solution.maxHeight(cuboids1) << endl;

    // Example 2:
    vector<vector<int>> cuboids2 = {{38, 25, 45}, {76, 35, 3}};
    cout << "Example 2: " << solution.maxHeight(cuboids2) << endl;

    // Example 3:
    vector<vector<int>> cuboids3 = {{7, 11, 17}, {7, 17, 11}, {11, 7, 17}, {11, 17, 7}, {17, 7, 11}, {17, 11, 7}};
    cout << "Example 3: " << solution.maxHeight(cuboids3) << endl;

    return 0;
}
