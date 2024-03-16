#include<bits/stdc++.h>
using namespace std;

//creating adjacency list and dfs
class Solution {
public:
    void dfs(vector<vector<int>>& graph,int src,vector<bool> &visited){
        visited[src]=true;
        for(int u: graph[src]){
            if(!visited[u]){
                dfs(graph,u,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n,vector<int>(n,0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int count=0; 
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};

//without adjacency list representation
void dfs(vector<vector<int>>& graph,int src,vector<bool> &visited,int &n){
    visited[src]=true;
    for(int u=0;u<n;u++){
        if(graph[src][u]==1 && !visited[u]){
            dfs(graph,u,visited,n);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
    vector<bool> visited(n, false);
    int count=0; 
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            dfs(isConnected,i,visited,n);
        }
    }
    return count;
}