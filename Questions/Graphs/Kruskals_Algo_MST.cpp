#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    static bool myComp(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }

public:
    int findParent(vector<int>& parent, int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]); // path compression
    }

    void union_set(int u, int v, vector<int>& parent, vector<int>& rank){
        u = findParent(parent, u);
        v = findParent(parent, v);
        if(rank[u] < rank[v]){
            parent[u] = v;
            rank[v]++;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<int> parent(V);
        vector<int> rank(V, 0);
        // Initialize each node as independent:
        for(int u = 0; u < V; u++){
            parent[u] = u;
        }

        // Create a Linear Data Structure that has w (sorted), u and v:
        vector<vector<int>> edges;
        for(int u = 0; u < V; u++){
            for(auto edge: adj[u]){
                int v = edge[0];
                int w = edge[1];
                edges.push_back({u, v, w});
            }
        }

        sort(edges.begin(), edges.end(), myComp);

        int ans = 0;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            u = findParent(parent, u);
            v = findParent(parent, v);
            
            if(u != v){
                union_set(u, v, parent, rank);
                ans += w;
            }
        }

        return ans;
    }
};

int main() {
    // Example usage:
    Solution solution;

    // Define your graph input (adjacency list representation):
    int V = 4;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 1}); // Edge from node 0 to node 1 with weight 1
    adj[0].push_back({2, 3}); // Edge from node 0 to node 2 with weight 3
    adj[1].push_back({2, 2}); // Edge from node 1 to node 2 with weight 2
    adj[1].push_back({3, 1}); // Edge from node 1 to node 3 with weight 1
    adj[2].push_back({3, 4}); // Edge from node 2 to node 3 with weight 4

    // Call the spanningTree method to find the sum of weights of edges of the Minimum Spanning Tree.
    int sum_of_weights = solution.spanningTree(V, adj);
    cout << "Sum of weights of edges of the Minimum Spanning Tree: " << sum_of_weights << endl;

    return 0;
}
