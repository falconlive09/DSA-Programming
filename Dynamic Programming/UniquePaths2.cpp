#include <bits/stdc++.h> 
using namespace std;
//Tabulation Solution
int mod=(int)(1e9+7);
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1)
                dp[i][j]=0;
            else if(i==0 && j==0) 
                dp[0][0]=1;
            else{
                int up=0,left=0;
                if(i>0) 
                    up=dp[i-1][j];
                if(j>0)
                    left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
//Space Optimization
int mod=(int)(1e9+7);
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    vector<int> prev(m,0);
    for(int i=0;i<n;i++){
        vector<int> cur(m,0);
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1)
                cur[j]=0;
            else if(i==0 && j==0) 
                cur[j]=1;
            else{
                int up=0,left=0;
                if(i>0) 
                    up=prev[j];
                if(j>0)
                    left=cur[j-1];
                cur[j]=(up+left)%mod;
            }
        }
        prev=cur;
    }
    return prev[m-1];
}

//LEETCODE SOLUTION
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {  
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();
    vector<int> prev(m,0);
    for(int i=0;i<n;i++){
        vector<int> cur(m,0);
        for(int j=0;j<m;j++){
            if(obstacleGrid[i][j]==1)
                cur[j]=0;
            else if(i==0 && j==0) 
                cur[j]=1;
            else{
                int up=0,left=0;
                if(i>0) 
                    up=prev[j];
                if(j>0)
                    left=cur[j-1];
                cur[j]=(up+left);
            }
        }
        prev=cur;
    }
    return prev[m-1];
    }
};