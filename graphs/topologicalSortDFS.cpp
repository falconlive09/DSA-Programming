#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> t; 
        stack<int>st;
        bool visited[V];
        for(int i=0;i<V;i++)
            visited[i]=false;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
                DFS(adj,i,st,visited);
        } 
        while(st.empty()==false)
        {
            t.push_back(st.top());
            st.pop();
        }
        return t;
	}
	void DFS(vector<int>*adj,int &s,stack<int>&st,bool *visited) //send the stack as a reference vv imp.
	{ // passing everything by reference
	    visited[s]=true;
	    for(int u:adj[s])
	    {
	        if(visited[u]==false)
	            DFS(adj,u,st,visited);
	    }
	    st.push(s);
	}
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends