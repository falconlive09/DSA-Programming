#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int timer=1;
    private:
        void DFS(int node,int parent,vector<bool> &visited,vector<int> &time,vector<int> &low,
		vector<int> &mark, vector<int> *adj)
        {
            visited[node]=true;
            time[node]=low[node]=timer;
            timer++;
			int child=0; //for parent articulation
            for(auto it: adj[node])
            {
                if(it==parent) // if adjacent node is the parent we dont consider it 
                    continue;
                if(visited[it]==0) //not visited
                {
                    DFS(it,node,visited,time,low,mark,adj);
                    low[node]= min(low[node],low[it]);
                    if(low[it]>=time[node] && parent!=-1)
                        mark[node]=1;
					child++;
                }
                else
                {
                    low[node]= min(low[node],time[it]);
                }     
                if (child > 1 && parent == -1) {
                    mark[node] = 1;
                }
            }
        }	
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
    {
        vector<bool> visited(V, false);
        vector<int> time(V,0);
        vector<int> low(V,0);
        vector<int> mark(V,0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, -1, visited, time, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) return { -1};
        return ans;
    }
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends