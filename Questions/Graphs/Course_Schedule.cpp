class Solution {
public:
    void topSortBfs(int n, vector<int>& topoOrder,unordered_map<int,list<int>>&adj) {
		queue<int> q;
		map<int,int> indegree;
		
		//initialise kardi indegree ssanki
		for( auto i : adj) {
			for(auto nbr: i.second) {
				indegree[nbr]++;
			}
		}
		//push all zero indegree wali node into queue
		for(int node=0; node<n; node++) {
			if(indegree[node] == 0) {
				q.push(node);
			}
		}

		//BFS chalate hai
		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();
			topoOrder.push_back(frontNode);

			for(auto nbr: adj[frontNode]) {
				indegree[nbr]--;

				//check for zero
				if(indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        for(vector<int>i : prerequisites){
            int u = i[0] ;//src
            int v = i[1] ; //dest
            adj[v].push_back(u) ;
        }
        vector<int>topoSort;
        topSortBfs(numCourses,topoSort,adj) ;
        if(topoSort.size()==numCourses){
            return true;
        }
        else 
            return false;
    }
};