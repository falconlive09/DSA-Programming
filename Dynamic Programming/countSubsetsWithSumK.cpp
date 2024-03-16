#include<bits/stdc++.h>
using namespace std;
int mod=(int)(1e9+7);
//memoization
int f(int ind,vector<int> &arr,int sum,vector<vector<int>> &dp)
{
    if(sum==0)
        return 1;
    if(ind==0)
        return (arr[0]==sum);
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    int notPick=f(ind-1,arr,sum,dp);
    int pick=0;
    if(arr[ind]<=sum)
        pick=f(ind-1,arr,sum-arr[ind],dp);
    return dp[ind][sum]=(notPick+pick)%mod;
}
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1,arr,k,dp);
}  

//Tabulation
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    for(int i=0;i<n;i++)   
        dp[i][0]=1;
    if(arr[0]<=k)
        dp[0][arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=k;sum++){
            int notPick=dp[ind-1][sum];
            int pick=0;
            if(arr[ind]<=sum)
                pick=dp[ind-1][sum-arr[ind]];
            dp[ind][sum]=notPick+pick;
        }
    }
    return dp[n-1][k];
}

//Space optimisation
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<int> prev(k+1,0),curr(k+1);  
    prev[0]=1,curr[0]=1;
    if(arr[0]<=k)
        prev[arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=k;sum++){
            int notPick=prev[sum];
            int pick=0;
            if(arr[ind]<=sum)
                pick=prev[sum-arr[ind]];
            curr[sum]=notPick+pick;
        }
        prev=curr;
    }
    return prev[k];
}

//For {0,0,1}
int f(int ind,vector<int> &arr,int sum,vector<vector<int>> &dp)
{
    if(ind==0){
        if(sum==0 && arr[0]==0)
            return 2;
        if(sum==0 || sum==arr[0])
            return 1;
        return 0;
    }
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    int notPick=f(ind-1,arr,sum,dp);
    int pick=0;
    if(arr[ind]<=sum)
        pick=f(ind-1,arr,sum-arr[ind],dp);
    return dp[ind][sum]=(notPick+pick)%mod;
}
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1,arr,k,dp);
}