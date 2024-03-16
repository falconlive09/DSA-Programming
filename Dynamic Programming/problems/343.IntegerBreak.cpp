#include <bits/stdc++.h>
using namespace std;

//recursive
class Solution {
public:
    int f(int n){
        if(n==2)    return 1;
        int result=0;
        for(int i=1;i<n;i++)
            result=max(result,i*max(n-i,f(n-i)));
        return result;
    }
    int integerBreak(int n) {
        return f(n);
    }
};

//Memoization
int f(int n,vector<int> &dp){
    if(n==2)    return 1;
    if(dp[n]!=-1)   return dp[n];
    int result=0;
    for(int i=1;i<n;i++)
        result=max(result,i*max(n-i,f(n-i,dp)));
    return dp[n]=result;
}
int integerBreak(int n) {
    vector<int> dp(n+1,-1);
    return f(n,dp);
}

//Tabulation
int integerBreak(int n) {
    vector<int> dp(n+1,0);
    dp[2]=1; //base case
    for(int i=3;i<=n;i++){
        for(int j=1;j<i;j++)
            dp[i]=max(dp[i],j*max(i-j,dp[i-j]));
    }
    return dp[n];
}