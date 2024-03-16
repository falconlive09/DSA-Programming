#include<bits/stdc++.h>
using namespace std;

//Recursive
int f(int ind,int N,vector<int> &price)
{
    if(ind==0)
    {
        if((ind+1)<=N)
            return price[ind]*(N/(ind+1));
        else
            return 0;
    }
    int notTake=f(ind-1,N,price);
    int Take=-1e9;
    if((ind+1)<=N)
        Take=price[ind]+f(ind,N-(ind+1),price);
    return max(Take,notTake);
}
int cutRod(vector<int> &price, int n)
{
    return f(n-1,n,price);
}

//Memoization
int f(int ind,int N,vector<int> &price,vector<vector<int>> &dp)
{
    if(ind==0)
    {
        if((ind+1)<=N)
            return price[ind]*(N/(ind+1));
        else
            return 0;
    }
    if(dp[ind][N]!=-1)
        return dp[ind][N];
    int notTake=f(ind-1,N,price,dp);
    int Take=-1e9;
    if((ind+1)<=N)
        Take=price[ind]+f(ind,N-(ind+1),price,dp);
    return dp[ind][N]=max(Take,notTake);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(n-1,n,price,dp);
}

//Tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    for(int N=0;N<=n;N++)
        dp[0][N]=price[0]*N;
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int notTake=dp[ind-1][N];
            int Take=-1e9;
            if((ind+1)<=N)
                Take=price[ind]+dp[ind][N-(ind+1)];
            dp[ind][N]=max(Take,notTake);
        }
    }
    return dp[n-1][n];
}

//Space Optimised
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int N=0;N<=n;N++)
        prev[N]=price[0]*N;
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int notTake=prev[N];
            int Take=-1e9;
            if((ind+1)<=N)
                Take=price[ind]+curr[N-(ind+1)];
            curr[N]=max(Take,notTake);
        }
        prev=curr;
    }
    return prev[n];
}

//further optimised
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1,0);
    for(int N=0;N<=n;N++)
        prev[N]=price[0]*N;
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int notTake=prev[N];
            int Take=-1e9;
            if((ind+1)<=N)
                Take=price[ind]+prev[N-(ind+1)];
            prev[N]=max(Take,notTake);
        }
    }
    return prev[n];
}