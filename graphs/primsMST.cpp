//O(ElogV) Optimised Prims Algorithm
#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pr,vector<pr>,greater<pr>>pq; //min heap for extraction of min
        int key[V],res=0;
        fill(key,key+V,INT_MAX); 
        key[0]=0; //key[]={0,∞,∞,∞,∞}
        vector<bool> mSet(V,false);
        pq.push({0,0});
        while(!pq.empty())
        {
            //picking min key vertex
            int u=pq.top().second; //node is at second positon
            pq.pop();
            if(mSet[u]==true) //if already visited continue searching for next node  
                continue; 
            //after picking marking it a part of mst set.
            mSet[u]=true;
            //adding its key to the result
            res+=key[u];
            for(auto it:adj[u]) //traversing the adjacents of u
            {   //updating the key value of the adjacent if we are getting a less key value
                int v=it[0];
                int weight=it[1];
                if(mSet[v]==false && key[v]>weight) //ALSO CHECK STRIVER IMPLEMENTATION WITHOUT key[] array
                {
                    key[v]=weight;
                    pq.push(make_pair(key[v], v));
                }
            }
        }
        return res;
    }
};


// } Driver Code Starts
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends