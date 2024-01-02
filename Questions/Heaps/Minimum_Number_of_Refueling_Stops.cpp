#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int fuel = startFuel;
        int dist = 0;
        int stops = 0;
        int i = 0;
        //creating a maxHeap to store the stations with max fuel within our fuel dist
        priority_queue<pair<int, int>> pq;
        while (true) {
            while (i < stations.size()) {
                if (stations[i][0] <= fuel + dist) { //if stations within range of dist :
                    pq.push({stations[i][1], stations[i][0]}); //heap fuel,pos
                } else
                    break;
                ++i;
            }
            dist += fuel; //travelling the dist with all fuel
            fuel = 0; //utilising all fuel
            //reached so exit as we reach or overshoot destination
            if (dist >= target) break;

            //travelled all dist with fuel but no stops in between but cant reach target so -1:
            if (pq.empty()) return -1;
            //refuel ans re-adjust dist and fuel based on dist travelled
            auto& top = pq.top();
            fuel = (dist - top.second) + top.first;
            dist = top.second;
            pq.pop();
            stops++;
        }
        return stops;
    }
};

int main() {
    Solution sol;

    // Example 1
    int target1 = 100, startFuel1 = 10;
    vector<vector<int>> stations1 = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    cout << "Output 1: " << sol.minRefuelStops(target1, startFuel1, stations1) << endl;

    // Example 2
    int target2 = 1, startFuel2 = 1;
    vector<vector<int>> stations2 = {};
    cout << "Output 2: " << sol.minRefuelStops(target2, startFuel2, stations2) << endl;

    // Example 3
    int target3 = 100, startFuel3 = 1;
    vector<vector<int>> stations3 = {{10, 100}};
    cout << "Output 3: " << sol.minRefuelStops(target3, startFuel3, stations3) << endl;

    return 0;
}
