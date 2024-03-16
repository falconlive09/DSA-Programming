#include <bits/stdc++.h>
using namespace std;

//Memoization
int f(int ind,int W,vector<int> &weight,vector<int> &value,vector<vector<int>> &dp)
{
    if(ind==0){
        if(weight[0]<=W)
            return value[0]*(W/weight[0]);
        else 
            return 0;
    }
    if(dp[ind][W]!=-1)
        return dp[ind][W];
    int notTake=0+f(ind-1,W,weight,value,dp);
    int take=-1e9;
    if(weight[ind]<=W)
        take=value[ind]+f(ind,W-weight[ind],weight,value,dp);
    return dp[ind][W]=max(take,notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return f(n-1,w,weight,profit,dp);
}   

//Tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    for(int W=0;W<=w;W++)
        dp[0][W]=profit[0]*(W/weight[0]);
    
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int notTake=0+dp[ind-1][W];
            int take=-1e9;
            if(weight[ind]<=W)
                take=profit[ind]+dp[ind][W-weight[ind]];
            dp[ind][W]=max(take,notTake);
        }
    }
    return dp[n-1][w];
}

//Space Optimisation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1,0),curr(w+1,0);
    for(int W=0;W<=w;W++)
        prev[W]=profit[0]*(W/weight[0]);
    
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int notTake=0+prev[W];
            int take=-1e9;
            if(weight[ind]<=W)
                take=profit[ind]+curr[W-weight[ind]];
            curr[W]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[w];
}

//further optimised
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1,0);
    for(int W=0;W<=w;W++)
        prev[W]=profit[0]*((int)(W/weight[0]));
    
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int notTake=0+prev[W];
            int take=-1e9;
            if(weight[ind]<=W)
                take=profit[ind]+prev[W-weight[ind]];
            prev[W]=max(take,notTake);
        }
    }
    return prev[w];
}