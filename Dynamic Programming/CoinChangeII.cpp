#include<bits/stdc++.h>
using namespace std;
//Memoization
long f(int ind,int target,int *denominations,vector<vector<long>> &dp)
{
    if(ind==0){
        if(target%denominations[ind]==0)
            return 1;
        else   
            return 0;
    }
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    long notTake=f(ind-1,target,denominations,dp);
    long take=0;
    if(denominations[ind]<=target)
        take=f(ind,target-denominations[ind],denominations,dp);
    return dp[ind][target]=take+notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    long ans=f(n-1,value,denominations,dp);
    return ans;
}

//Tabulation
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    for(int target=0;target<=value;target++){
        if(target%denominations[0]==0)
            dp[0][target]=1;
        else   
            dp[0][target]=0;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=value;target++){
            long notTake=dp[ind-1][target];
            long take=0;
            if(denominations[ind]<=target)
                take=dp[ind][target-denominations[ind]];
            dp[ind][target]=take+notTake;
        }
    }
    return dp[n-1][value];
}

//Space Optimisation
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value+1,0),curr(value+1,0);
    for(int target=0;target<=value;target++){
        if(target%denominations[0]==0)
            prev[target]=1;
        else   
            prev[target]=0;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=value;target++){
            long notTake=prev[target];
            long take=0;
            if(denominations[ind]<=target)
                take=curr[target-denominations[ind]];
            curr[target]=take+notTake;
        }
        prev=curr;
    }
    return prev[value];
}
//further optimised
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value+1,0),curr(value+1,0);
    for(int target=0;target<=value;target++){
        if(target%denominations[0]==0)
            prev[target]=1;
        else   
            prev[target]=0;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=value;target++){
            long notTake=prev[target];
            long take=0;
            if(denominations[ind]<=target)
                take=prev[target-denominations[ind]];
            prev[target]=take+notTake;
        }
    }
    return prev[value];
}