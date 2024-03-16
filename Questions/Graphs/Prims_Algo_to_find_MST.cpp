#include <iostream>
#include <vector>
#include<limits.h>

using namespace std;
//Prims Algo :
class Solution {
public:
    int findMinNode(vector<int> &key, vector<bool> &mst) {
        int temp = INT_MAX;
        int index = -1; // represents the actual node having min value
        for (int i = 0; i < key.size(); i++) {
            if (key[i] < temp && mst[i] == false) {
                temp = key[i];
                index = i;
            }
        }
        return index;
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> key(V, INT_MAX);  // stores weights of each nodes
        vector<bool> mst(V, false);   // tracks which node has been included in MST
        vector<int> parent(V, -1);     // stores final mst relation

        // initializing initial source :
        key[0] = 0;
        while (true) {
            // step1 : find min node u :
            int u = findMinNode(key, mst);
            if (u == -1) break;
            // step 2: mark mst[u]
            mst[u] = true;

            // step3 : process all adj node to u :
            for (auto edge : adj[u]) {
                int v = edge[0];
                int w = edge[1];
                if (mst[v] == false && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < key.size(); i++) {
            sum += key[i];
        }
        // find the sum of weights of the edges of mst :
        return sum;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];

    // Taking input for the adjacency list
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // If the graph is undirected
    }

    Solution sol;
    int minSpanningTreeWeight = sol.spanningTree(V, adj);
    cout << "Output:" << endl;
    cout << minSpanningTreeWeight << endl;

    return 0;
}
