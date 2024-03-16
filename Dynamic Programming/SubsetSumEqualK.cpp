#include <bits/stdc++.h> 
using namespace std;
//Memoization
bool f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp)
{
    if(target==0)
        return true;
    if(ind==0)
        return (arr[0]==target);
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    bool noTake=f(ind-1,target,arr,dp);
    bool take=false;
    if(target>=arr[ind])
        take=f(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target]=take || noTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return f(n-1,k,arr,dp);
}
//Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    if(arr[0]<=k) //to prevent runtime error
        dp[0][arr[0]]=true; //at index 0
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool noTake=dp[ind-1][target];
            bool take=false;
            if(target>=arr[ind])
                take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=take || noTake;
        }
    }
    return dp[n-1][k];
}
//Space Optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, 0), cur(k+1,0); //k columns only 1 row
    prev[0]=cur[0]=true;
    if(arr[0]<=k) //to prevent runtime error
        prev[arr[0]]=true; //at index 0
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool noTake=prev[target];
            bool take=false;
            if(target>=arr[ind])
                take=prev[target-arr[ind]];
            cur[target]=take || noTake;
        }
        prev=cur;
    }
    return prev[k];
}