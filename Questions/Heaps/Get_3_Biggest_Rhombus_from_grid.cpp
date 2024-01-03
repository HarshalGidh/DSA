#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool validVertices(vector<vector<int>>& grid, vector<pair<int, int>>& v) {
        int m = grid.size();
        int n = grid[0].size();
        for (auto pt : v) {
            if (pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n) {
                return false;
            }
        }
        return true;
    }

    bool makeVertices(vector<vector<int>>& grid, vector<pair<int, int>>& v, int& delta, pair<int, int> points) {
        //create vertices :
        pair<int, int> A(points.first - delta, points.second);
        pair<int, int> B(points.first, points.second + delta);
        pair<int, int> C(points.first + delta, points.second);
        pair<int, int> D(points.first, points.second - delta);
        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;
        //check if all vertices are inBound if yes then return valid vertices:
        if (validVertices(grid, v)) {
            return true;
        }
        return false;
    }

    void getAllSum(vector<vector<int>>& grid, priority_queue<int>& pq, int& cx, int& cy) {
        //push the single cell value in heap:
        pq.push(grid[cx][cy]);
        //create rhombus around the cell  :
        int delta = 1;
        vector<pair<int, int>> v(4); //creating points for vertices
        while (makeVertices(grid, v, delta, {cx, cy})) {
            pair<int, int>& A = v[0];
            pair<int, int>& B = v[1];
            pair<int, int>& C = v[2];
            pair<int, int>& D = v[3];
            //add all the vertices sum :
            int csum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];
            //create boundary points and get their sum
            //Boundary points AB:
            for (int i = 1; i < (B.first - A.first); i++) {
                csum += grid[A.first + i][A.second + i];
            }
            //Boundary points BC:
            for (int i = 1; i < (C.first - B.first); i++) {
                csum += grid[B.first + i][B.second - i];
            }
            //Boundary points CD:
            for (int i = 1; i < (C.first - D.first); i++) {
                csum += grid[C.first - i][C.second - i];
            }
            //Boundary points DA:
            for (int i = 1; i < (D.first - A.first); i++) {
                csum += grid[D.first - i][D.second + i];
            }
            pq.push(csum); //RH sum has been pushed
            ++delta;
        }
    }

    bool isDifferent(vector<int>& ans, int& top) {
        for (auto val : ans) {
            if (val == top) {
                return false;
            }
        }
        return true;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size();
        int n = grid[0].size();
        //creating Max Heap to get top 3 biggest rhombus :
        priority_queue<int> pq;
        //pushing grid elements in Heap :
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                getAllSum(grid, pq, i, j);
            }
        }
        while (!pq.empty() && ans.size() < 3) {
            int top = pq.top();
            pq.pop();
            //to get distinct rhombus sum in ans :
            if (isDifferent(ans, top)) {
                ans.push_back(top);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> grid1 = {{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}};
    vector<int> output1 = sol.getBiggestThree(grid1);
    cout << "Output 1: [";
    for (int i = 0; i < output1.size(); i++) {
        cout << output1[i];
        if (i != output1.size() - 1)
            cout << ", ";
    }
    cout << "]\n";

    // Example 2
    vector<vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> output2 = sol.getBiggestThree(grid2);
    cout << "Output 2: [";
    for (int i = 0; i < output2.size(); i++) {
        cout << output2[i];
        if (i != output2.size() - 1)
            cout << ", ";
    }
    cout << "]\n";

    // Example 3
    vector<vector<int>> grid3 = {{7, 7, 7}};
    vector<int> output3 = sol.getBiggestThree(grid3);
    cout << "Output 3: [";
    for (int i = 0; i < output3.size(); i++) {
        cout << output3[i];
        if (i != output3.size() - 1)
            cout << ", ";
    }
    cout << "]\n";

    return 0;
}
