#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int target,int i)
    {
        int power=i*i;
        if(target==0)
            return 0;
        if(target<0 || power>target)
            return 1e9;
        int notTake=f(target,i+1);
        int Take=1e9;
        if(power<=target)
            Take=1+f(target-power,i);
        return min(Take,notTake);
    }
    int numSquares(int n) {
        return f(n,1);
    }
};

//memoization
int f(int target,int i,vector<int> &dp)
{
    if(target==0)
        return 0;
    if(target<0 || i*i>target)
        return 1e9;
    if(dp[target]!=-1)
        return dp[target];
    int notTake=f(target,i+1,dp);
    int Take=1e9;
    if(i*i<=target)
        Take=1+f(target-i*i,i,dp);
    return dp[target]=min(Take,notTake);
}
int numSquares(int n) {
    vector<int> dp(n + 1, -1);
    return f(n,1,dp);
}

//Tabulation
int numSquares(int n) {
    vector<int> dp(n + 1, 1e9);
    dp[0]=0;
    for(int target=1;target<=n;target++)
    {
        for(int i=1;i*i<=target;i++)
        {
            int notTake=dp[target];
            int Take=1e9;
            if(i*i<=target)
                Take=1+dp[target-i*i];
            dp[target]=min(Take,notTake);
        }
    }
    return dp[n];
}