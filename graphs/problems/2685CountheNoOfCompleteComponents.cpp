#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph,int src,vector<bool> &visited,int &nodes,int &edges){
        visited[src]=true;
        nodes++;
        edges+=graph[src].size();
        for(int u: graph[src]){
            if(!visited[u]){
                //edges++; will not work for cycle as the edge which connects to the parent node will not be counted.              
                dfs(graph,u,visited,nodes,edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int count=0; 
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int nodes=0,edges=0;
                dfs(adj,i,visited,nodes,edges);
                edges/=2; //as each edge is counted twice
                if(edges==nodes*(nodes-1)/2)
                    count++;
            }
        }
        return count;
    }
};

/*Hint
Find the connected components of an undirected graph using depth-first search (DFS)
or breadth-first search (BFS).
For each connected component, count the number of nodes and edges in the component.
 
A connected component is complete if and only if the number of edges in the component 
is equal to m*(m-1)/2, where m is the number of nodes in the component.*/