#include<bits/stdc++.h>
using namespace std;

class Solution {
private:   
    void dfs(vector<vector<int>>& graph,int src,vector<bool> &visited){
        visited[src]=true;
        for(int u: graph[src]){
            if(!visited[u]){                    
                dfs(graph,u,visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        dfs(rooms,0,visited);
        for(int i=0;i<rooms.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};