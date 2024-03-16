#include <bits/stdc++.h> //based on topological sorting
#define INF INT_MAX/2 //otherwise it will overflow

using namespace std;

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int>dist(N,INF);
        dist[0]=0;
        vector<int>topo;
        vector<int>inDegree(N,0);
        for(int i=0;i<M;i++)
        {
            inDegree[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<N;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int u=q.front(); 
            q.pop();
            topo.push_back(u);
            for(int i=0;i<M;i++)
            {
                if(edges[i][0]==u)
                {
                    if(dist[edges[i][1]]>dist[u]+edges[i][2]) //finding shortest path
                    {
                        dist[edges[i][1]]=dist[u]+edges[i][2];
                    }
                    inDegree[edges[i][1]]--;
                    if(inDegree[edges[i][1]]==0) //doing topological sort
                        q.push(edges[i][1]);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (dist[i] == INF)
                dist[i] = -1;
        }
        for(auto x:topo)
            cout<<x<<" ";
        cout<<"\n";
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
// } Driver Code Ends


/*HOW TO INPUT
1
0 1 2
2 1 2
2 4 2
1 4 8
1 3 6
*/