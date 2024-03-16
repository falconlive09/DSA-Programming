#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>> &adj,int src,vector<bool> &visited,int seats,long long &fuel){
        visited[src]=true;
        int people=1;
        for(auto i:adj[src]){
            if(!visited[i]){
                people+=dfs(adj,i,visited,seats,fuel);
            }
        }
        if(src!=0)
            fuel += static_cast<long long>(ceil(1.0 * people / seats)); 
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<bool> visited(n,false);
        long long fuel=0;
        dfs(adj,0,visited,seats,fuel);
        return fuel;
    }
};