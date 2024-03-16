#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX/2
#define pr pair<int,int>
class Solution {
public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int>dist(V,INF);
        dist[S]=0;
        priority_queue<pr,vector<pr>,greater<pr>>pq; //min heap for extraction of min
        pq.push({0,S});
        while(!pq.empty()) {
            int u=pq.top().second;
            int currDist = pq.top().first;
            pq.pop();
            for(auto it:adj[u]) {
                int v=it[0];
                int weight=it[1];
                if(dist[v]>currDist+weight) {   
                    dist[v]=currDist+weight;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
// } Driver Code Ends