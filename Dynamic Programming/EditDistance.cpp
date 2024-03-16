#include<bits/stdc++.h>
using namespace std;

//Recursive
class Solution {
public:
    int f(int i,int j,string &s1,string &s2)
    {
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(s1[i]==s2[j])
            return f(i-1,j-1,s1,s2);
        return 1+min(f(i-1,j,s1,s2),min(f(i,j-1,s1,s2),f(i-1,j-1,s1,s2)));
    }
    int minDistance(string &word1, string &word2) {   
        int n=word1.size();
        int m=word2.size();
        return f(n-1,m-1,word1,word2); 
    }
};

//Memoization
int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
{
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]==s2[j])
        return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    return dp[i][j]=1+min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
}
int minDistance(string &word1, string &word2) {   
    int n=word1.size();
    int m=word2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,word1,word2,dp); 
}

//Shifted Memoization
int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
{
    if(i==0)
        return j;
    if(j==0)
        return i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i-1]==s2[j-1])
        return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    return dp[i][j]=1+min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
}
int minDistance(string &word1, string &word2) {   
    int n=word1.size();
    int m=word2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return f(n,m,word1,word2,dp); 
}

//Tabulation
int minDistance(string &s1, string &s2) {   
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++)
        dp[0][j]=j;
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else    
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}

//Space Optimisation
int minDistance(string &s1, string &s2) {   
    int n=s1.size();
    int m=s2.size();
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++)
        prev[j]=j;
    //for(int i=0;i<=n;i++) Covered in initialisation
        //dp[i][0]=i;
    for(int i=1;i<=n;i++){
        curr[0]=i;
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                curr[j]=prev[j-1];
            else    
                curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
        }
        prev=curr;
    }
    return prev[m];
}