//Leetcode problem Critical Connections in a Network
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
int timer=1;
private:
    void DFS(int node,int parent,vector<bool> &visited,vector<int> *adj,
        vector<int> &time,vector<int> &low,vector<vector<int>> &bridge)
    {
        visited[node]="true";
        time[node]=low[node]=timer;
        timer++;
        for(auto it: adj[node])
        {
            if(it==parent) // if adjacent node is the parent we dont consider it 
                continue;
            if(visited[it]==0)
            {
                DFS(it,node,visited,adj,time,low,bridge);
                low[node]= min(low[node],low[it]);
                // node -- it (bridge)
                if(low[it]>time[node])
                    bridge.push_back({it,node});
            }
            else
            {
                low[node]= min(low[node],low[it]);
            }      
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n, false);
        vector<int> time(n,0);
        vector<int> low(n,0);
        vector<vector<int>> bridge; 
        DFS(0,-1,visited,adj,time,low,bridge);
        return bridge;
    }
};