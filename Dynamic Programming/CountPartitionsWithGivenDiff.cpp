#include <bits/stdc++.h> 
using namespace std;
int mod=(int)(1e9+7);
//Memoization
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
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(auto &it:arr)
        totSum+=it;
    if(totSum-d<0 || (totSum-d)%2)
        return 0;
    return findWays(arr,(totSum-d)/2);
}

//Tabulation
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    if(arr[0]==0)
        dp[0][0]=2; //at index 0, we can either pick or not pick
    else
        dp[0][0]=1; //at index 0 the sum is 0 but arr[0] is not 0 so not pick 
    //arr[0]=0
    if(arr[0]!=0 && arr[0]<=k) //if arr[0] is 0 then we have already considered it which is =2
        dp[0][arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=k;sum++){
            int notPick=dp[ind-1][sum];
            int pick=0;
            if(arr[ind]<=sum)
                pick=dp[ind-1][sum-arr[ind]];
            dp[ind][sum]=(notPick+pick)%mod;
        }
    }
    return dp[n-1][k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(auto &it:arr)
        totSum+=it;
    if(totSum-d<0 || (totSum-d)%2)
        return 0;
    return findWays(arr,(totSum-d)/2);
}
//Space Optimisation
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<int> prev(k+1,0),curr(k+1);  
    if(arr[0]==0)
        prev[0]=2; //at index 0, we can either pick or not pick
    else
        prev[0]=1; //at index 0 the sum is 0 but arr[0] is not 0 so not pick 
    //arr[0]=0
    if(arr[0]!=0 && arr[0]<=k) //if arr[0] is 0 then we have already considered it which is =2
        prev[arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=k;sum++){
            int notPick=prev[sum];
            int pick=0;
            if(arr[ind]<=sum)
                pick=prev[sum-arr[ind]];
            curr[sum]=(notPick+pick)%mod;
        }
        prev=curr;
    }
    return prev[k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(auto &it:arr)
        totSum+=it;
    if(totSum-d<0 || (totSum-d)%2)
        return 0;
    return findWays(arr,(totSum-d)/2);
}