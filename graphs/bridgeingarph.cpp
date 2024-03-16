#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    int timer=1;
    private:
        void DFS(int node,int parent,vector<bool> &visited,vector<int> *adj,
            vector<int> &time,vector<int> &low,vector<vector<int>> &bridge)
        {
            visited[node]=true;
            time[node]=low[node]=timer;
            timer++;
            for(auto it: adj[node])
            {
                if(it==parent) // if adjacent node is the parent we dont consider it 
                    continue;
                if(visited[it]==0) //not visited
                {
                    DFS(it,node,visited,adj,time,low,bridge);
                    low[node]= min(low[node],low[it]);
                    // node -- it (bridge)
                    if(low[it]>time[node])
                        bridge.push_back({it,node});
                }
                else
                {
                    low[node]= min(low[node],low[it]);
                }      
            }
        }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool> visited(V, false);
        vector<int> time(V,0);
        vector<int> low(V,0);
        vector<vector<int>> bridge; 
        for(int i=0;i<V;i++) //Using this loop as the graph might be disconnected
        {
            if(!visited[i])
            DFS(i,-1,visited,adj,time,low,bridge); 
        } 
        for (auto pair : bridge) 
        {
            if ((pair[0] == c && pair[1] == d) || (pair[0] == d && pair[1] == c))
                return 1;
        }
        return 0; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends