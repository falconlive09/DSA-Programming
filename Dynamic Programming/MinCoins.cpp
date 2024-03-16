#include <bits/stdc++.h> 
using namespace std;

//Memoization
int f(int ind,int target,vector<int> &num,vector<vector<int>> &dp)
{
    if(ind==0){
        if(target%num[ind]==0)
            return target/num[ind];
        else   
            return 1e9;
    }
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    int notTake=f(ind-1,target,num,dp);
    int take=1e9;
    if(num[ind]<=target)
        take=1+f(ind,target-num[ind],num,dp);
    return dp[ind][target]=min(take,notTake);
}
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans=f(n-1,x,num,dp);
    if(ans==1e9)
        return -1;
    return ans;
}

//Tabulation
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    for(int target=0;target<=x;target++){
        if(target%num[0]==0)
            dp[0][target]=target/num[0];
        else   
            dp[0][target]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=x;target++){
            int notTake=dp[ind-1][target];
            int take=1e9;
            if(num[ind]<=target)
                take=1+dp[ind][target-num[ind]];
            dp[ind][target]=min(take,notTake);
        }
    }
    if(dp[n-1][x]==1e9)
        return -1;
    return dp[n-1][x];
}
//Space Optimisation
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<int> prev(x+1,0),curr(x+1,0);
    for(int target=0;target<=x;target++){
        if(target%num[0]==0)
            prev[target]=target/num[0];
        else   
            prev[target]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=x;target++){
            int notTake=prev[target];
            int take=1e9;
            if(num[ind]<=target)
                take=1+curr[target-num[ind]];
            curr[target]=min(take,notTake);
        }
        prev=curr;
    }
    if(prev[x]==1e9)
        return -1;
    return prev[x];
}
//further optimised
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<int> prev(x+1,0);
    for(int target=0;target<=x;target++){
        if(target%num[0]==0)
            prev[target]=target/num[0];
        else   
            prev[target]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=0;target<=x;target++){
            int notTake=prev[target];
            int take=1e9;
            if(num[ind]<=target)
                take=1+prev[target-num[ind]];
            prev[target]=min(take,notTake);
        }
    }
    if(prev[x]==1e9)
        return -1;
    return prev[x];
}