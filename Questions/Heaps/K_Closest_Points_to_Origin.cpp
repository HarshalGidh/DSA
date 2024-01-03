#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class compare {
public:
    bool operator()(pair<int, int> A, pair<int, int> B) {
        //calculate Distance of points :
        int distA = A.first * A.first + A.second * A.second;
        int distB = B.first * B.first + B.second * B.second;
        return distA > distB; //returns minimum
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        //Create Min Heap :
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        //Push points in Min Heap :
        for (auto p : points) {
            pq.push({p[0], p[1]});
        }
        //push in ans :
        while (!pq.empty() && k--) {
            auto& top = pq.top();
            ans.push_back({top.first, top.second});
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> points1 = {{1, 3}, {-2, 2}};
    int k1 = 1;
    vector<vector<int>> output1 = sol.kClosest(points1, k1);
    cout << "Output 1: [";
    for (int i = 0; i < output1.size(); i++) {
        cout << "[" << output1[i][0] << ", " << output1[i][1] << "]";
        if (i != output1.size() - 1)
            cout << ", ";
    }
    cout << "]\n";

    // Example 2
    vector<vector<int>> points2 = {{3, 3}, {5, -1}, {-2, 4}};
    int k2 = 2;
    vector<vector<int>> output2 = sol.kClosest(points2, k2);
    cout << "Output 2: [";
    for (int i = 0; i < output2.size(); i++) {
        cout << "[" << output2[i][0] << ", " << output2[i][1] << "]";
        if (i != output2.size() - 1)
            cout << ", ";
    }
    cout << "]\n";

    return 0;
}
