#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool cycleDetectionDFS(unordered_map<int,bool>& visited, int src, vector<int> adj[],
                           unordered_map<int,bool>& dfstrack, int safeNodes[]) {
        
        visited[src] = true;
        dfstrack[src] = true;
        safeNodes[src] = 0;
        
        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
                bool dfsAns = cycleDetectionDFS(visited, nbr, adj, dfstrack, safeNodes);
                if (dfsAns) return true;
            }
            if (visited[nbr] && dfstrack[nbr]) return true;
        }
        
        // Backtrack and mark dfstrack as false
        dfstrack[src] = false;
        safeNodes[src] = 1;
        return false;
    }
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int,bool> visited, dfstrack;
        int safeNodes[V] = {0};
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cycleDetectionDFS(visited, i, adj, dfstrack, safeNodes);
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (safeNodes[i]) ans.push_back(i);
        }
        
        return ans;
    }
};

int main() {
    // Example graph representation
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);

    // Call the function to find eventual safe nodes
    Solution sol;
    vector<int> result = sol.eventualSafeNodes(V, adj);

    // Print the eventual safe nodes
    cout << "Eventual Safe Nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
