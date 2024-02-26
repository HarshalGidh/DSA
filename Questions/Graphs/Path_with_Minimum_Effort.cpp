class Solution {
public:
 bool isSafe(int x, int y, int row, int col, vector<vector<int>>& diff) {
        return x >= 0 && y >= 0 && x < row && y < col;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> diff(row, vector<int>(col, INT_MAX));

        diff[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto topNode = pq.top();
            pq.pop();
            int currDiff = topNode.first;
            int currX = topNode.second.first;
            int currY = topNode.second.second;

            for (int i = 0; i < 4; i++) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if (isSafe(newX, newY, row, col, diff)) {
                    int maxDiff = max(currDiff, abs(heights[currX][currY] - heights[newX][newY]));
                    if (maxDiff < diff[newX][newY]) {
                        diff[newX][newY] = maxDiff;
                        pq.push({maxDiff, {newX, newY}});
                    }
                }
            }
        }

        return diff[row - 1][col - 1];
    }
};