#include <bits/stdc++.h> 
using namespace std;
//Memoization
int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
{
    if(i==0 && j==0)
        return grid[0][0];
    if(i<0 || j<0)
        return 1e9;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int left=0,up=0;
    up=grid[i][j]+f(i-1,j,grid,dp);
    left=grid[i][j]+f(i,j-1,grid,dp);
    return min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    return f(grid.size()-1,grid[0].size()-1,grid,dp);
}

//Tabulation
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)
                dp[i][j]=grid[i][j];
            else{
                
                int up=grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left=grid[i][j];
                if(j>0) left += dp[i][j-1];
                else left += 1e9;
                
                dp[i][j]=min(left,up);
            }
        }
    }
    return dp[n-1][m-1];
}
//Space Optimization
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int> prev(m,0);
    for(int i=0;i<n;i++){
        //i=n
        vector<int>cur(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0)
                cur[j]=grid[i][j];
            else{
                
                int up=grid[i][j];
                //requiring previous row's j column
                if(i>0) up += prev[j];
                else up += 1e9;
                
                int left=grid[i][j];
                //current row's j-1 column
                if(j>0) left += cur[j-1];
                else left += 1e9;
                
                cur[j]=min(left,up);
            }
        }
        prev=cur;
    }
    return prev[m-1];
}