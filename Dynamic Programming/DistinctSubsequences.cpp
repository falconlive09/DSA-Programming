#include<bits/stdc++.h>
using namespace std;

//Recursive
class Solution {
public:
    int f(int ind1,int ind2,string &s1,string &s2){
        if(ind2<0)
            return 1;
        if(ind1<0)
            return 0;
        int left=0;
        if(s1[ind1]==s2[ind2])
            left=f(ind1-1,ind2-1,s1,s2);
        int right=f(ind1-1,ind2,s1,s2);
        return left+right;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        return f(n-1,m-1,s,t);
    }
};
//Memoization
int f(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp){
    if(ind2<0)
        return 1;
    if(ind1<0)
        return 0;
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    int left=0;
    if(s1[ind1]==s2[ind2])
        left=f(ind1-1,ind2-1,s1,s2,dp);
    int right=f(ind1-1,ind2,s1,s2,dp);
    return dp[ind1][ind2]=left+right;
}
int numDistinct(string s, string t) {
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return f(n-1,m-1,s,t,dp);
}

//Memoization after shifting index
int f(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp){
    if(ind2==0)
        return 1;
    if(ind1==0)
        return 0;
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    int left=0;
    if(s1[ind1-1]==s2[ind2-1])
        left=f(ind1-1,ind2-1,s1,s2,dp);
    int right=f(ind1-1,ind2,s1,s2,dp);
    return dp[ind1][ind2]=left+right;
}
int numDistinct(string s, string t) {
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
    return f(n,m,s,t,dp);
}

//Tabulation
int numDistinct(string s, string t) {
    int n=s.size();
    int m=t.size();
    vector<vector<unsigned int>> dp(n+1,vector<unsigned int> (m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=m;j++){
        dp[0][j]=0; 
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            unsigned int left=0;
            if(s[i-1]==t[j-1])
                left=dp[i-1][j-1];
            unsigned int right=dp[i-1][j];
            dp[i][j]=(left+right);
        }
    }
    return dp[n][m];
}

//Space Optimisation
int numDistinct(string s, string t) {
    int n=s.size();
    int m=t.size();
    //storing previous rows value so size of prev array will be m
    vector<unsigned int> prev(m+1,0),curr(m+1,0);
    prev[0]=curr[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            unsigned int left=0;
            if(s[i-1]==t[j-1])
                left=prev[j-1];
            unsigned int right=prev[j];
            curr[j]=(left+right);
        }
        prev=curr;
    }
    return prev[m];
}

//Further Optimised
int numDistinct(string s, string t) {
    int n=s.size();
    int m=t.size();
    //storing previous rows value so size of prev array will be m
    vector<unsigned int> prev(m+1,0);
    prev[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            //unsigned int left=0;
            if(s[i-1]==t[j-1])
                //left=prev[j-1];
                prev[j]=prev[j-1]+prev[j];
            //unsigned int right=prev[j];
            //prev[j]=(left+right);
        }
    }
    return prev[m];
}