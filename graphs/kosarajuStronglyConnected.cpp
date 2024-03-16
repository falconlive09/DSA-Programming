#include<bits/stdc++.h>
using namespace std;

class Solution
{
	private:
    void DFS(vector<vector<int>>&adj,int &s,stack<int>&st,vector<bool> &visited) 
	{ 
	    visited[s]=true; 
	    for(int u:adj[s])
	    {
	        if(visited[u]==false)
	            DFS(adj,u,st,visited);
	    }
	    st.push(s);
	}
    void DFSRev(vector<vector<int>>&adj,int &s,vector<bool> &visited) 
	{ 
	    visited[s]=true; 
	    for(int u:adj[s])
	    {
	        if(visited[u]==false)
	            DFSRev(adj,u,visited);
	    }
	}
    public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) //Overall Complexity-> O(V+E)
    {
        //Space Complexity-> O(2*V)
        int V=adj.size();
        vector<bool>vis(V,false);
        stack<int>st;
        //O(V+E)
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false)
                DFS(adj,i,st,vis); //sorting of all edges
        }
        
        //Reversal of edges of graph or reversal of graph
        //O(V+E)
        vector<vector<int>>adjRev(V); //give size otherwise results in segmentation fault
        for(int j=0;j<V;j++)
        {   vis[j]=false; // Reusing the visited array for step 3
            for(int k:adj[j])
            {
                // j -> k
                // k -> j 
                adjRev[k].push_back(j); 
            }
        }
        //Perform DFS   
        //O(V+E)
        int scc=0;
        while(st.empty()==false)
        {
            int node=st.top();
            st.pop();
            if(!vis[node])
            {
                scc++;
                DFSRev(adjRev,node,vis);
            }
        }
        return scc;
    }    
};


// { Driver Code Starts.
int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends

/*HOW TO INPUT

1
5 5
1 0
0 2
2 1
0 3
3 4
EXPECTED OUTPUT
3
*/