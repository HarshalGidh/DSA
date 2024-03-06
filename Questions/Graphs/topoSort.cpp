#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // Include the algorithm header for reverse function

using namespace std;

class Solution
{
public:
    void dfs(int src, vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans)
    {
        visited[src] = true;
        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                dfs(nbr, adj, visited, ans);
            }
        }
        ans.push_back(src);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, ans);
            }
        }
        reverse(ans.begin(), ans.end()); // Reverse the order to get topological sorting
        return ans;
    }
};

int main()
{
    int V = 3, E = 4;
    vector<int> adj[V];
    adj[3].push_back(0);
    adj[1].push_back(0);
    adj[2].push_back(0);

    Solution obj;
    vector<int> result = obj.topoSort(V, adj);

    for (int vertex : result)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
