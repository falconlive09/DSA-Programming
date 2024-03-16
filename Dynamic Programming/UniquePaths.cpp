#include <bits/stdc++.h> 
using namespace std;
//Tabulation Solution
int uniquePaths(int m, int n) {    
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) 
                dp[0][0]=1;
            else{
                int up=0,left=0;
                if(i>0) 
                    up=dp[i-1][j];
                if(j>0)
                    left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}
//Space Optimization
int uniquePaths(int m, int n) {    
    vector<int> prev(n,0);
    for(int i=0;i<m;i++){
        vector<int> cur(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j==0) 
                cur[j]=1;
            else{
                int up=0,left=0;
                if(i>0) 
                    up=prev[j];
                if(j>0)
                    left=cur[j-1];
                cur[j]=up+left;
            }
        }
        prev=cur;
    }
    return prev[n-1];
}