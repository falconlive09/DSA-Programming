#include <bits/stdc++.h> 
using namespace std;
//Memoization
int f(int ind,int W,vector<int> &weight,vector<int> &value,vector<vector<int>> &dp)
{
    if(ind==0){
        if(weight[0]<=W)
            return value[0];
        else 
            return 0;
    }
    if(dp[ind][W]!=-1)
        return dp[ind][W];
    int notTake=0+f(ind-1,W,weight,value,dp);
    int take=-1e9;
    if(weight[ind]<=W)
        take=value[ind]+f(ind-1,W-weight[ind],weight,value,dp);
    return dp[ind][W]=max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return f(n-1,maxWeight,weight,value,dp);
}
//Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int i=weight[0];i<=maxWeight;i++)
        dp[0][i]=value[0];
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
            int notTake=0+dp[ind-1][W];
            int take=-1e9;
            if(weight[ind]<=W)
                take=value[ind]+dp[ind-1][W-weight[ind]];
            dp[ind][W]=max(take,notTake);
        }
    }
    return dp[n-1][maxWeight];
}
//Space Optimisation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);
    for(int i=weight[0];i<=maxWeight;i++)
        prev[i]=value[0];
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
            int notTake=0+prev[W];
            int take=-1e9;
            if(weight[ind]<=W)
                take=value[ind]+prev[W-weight[ind]];
            curr[W]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[maxWeight];
}
//further optimised
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0);
    for(int i=weight[0];i<=maxWeight;i++)
        prev[i]=value[0];
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
            int notTake=0+prev[W];
            int take=-1e9;
            if(weight[ind]<=W)
                take=value[ind]+prev[W-weight[ind]];
            prev[W]=max(take,notTake);
        }
    }
    return prev[maxWeight];
}