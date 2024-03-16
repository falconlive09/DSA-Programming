#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>>& graph,int src,vector<bool> &visited,
    vector<vector<int>> &ans,vector<int> &ds){
            visited[src]=true;
            ds.push_back(src);
            if(src==graph.size()-1){
                ans.push_back(ds);
            }
            for(int u: graph[src]){
                if(!visited[u]){                    
                    dfs(graph,u,visited,ans,ds);
                }
            }
            visited[src]=false;
            ds.pop_back(); 
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> visited(graph.size(),false);
        dfs(graph,0,visited,ans,ds);
        return ans;
    }   
};