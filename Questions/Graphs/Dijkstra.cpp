class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //create a set/Min-heap to get a min sorted dist of nodes :
        set<pair<int,int>>st ;
        vector<int>dist(V+1,INT_MAX); //dist arr
        //initial state : push src node with 0 dist
        st.insert({0,S}) ;
        int src = S ;
        dist[src] = 0;
        
        //iterate all nbrs and update distance of nbrs :
        while(!st.empty()){
            auto top = st.begin();
            pair<int,int>topPair = *top;
            int srcDis = topPair.first;
            int srcNode = topPair.second ;
            //remove top from set :
            st.erase(st.begin()) ;
            for(auto nbrPair : adj[srcNode]){
                int nbrNode = nbrPair[0] ;
                int nbrDis = nbrPair[1] ;
                //distance updation logic :
                if(srcDis + nbrDis < dist[nbrNode]){
                    
                    //if set already had nbrNode we need to update it
                    auto previousEntry = st.find({dist[nbrNode],nbrNode});
                    if(previousEntry  != st.end()){
                        //remove prev entry :
                        st.erase(previousEntry);
                    }
                    //update dist :
                    dist[nbrNode] = srcDis + nbrDis ;
                    //create new entry in set :
                    st.insert({dist[nbrNode],nbrNode}) ;
                }
            }
        }
        return dist; //return dist array
    }
};