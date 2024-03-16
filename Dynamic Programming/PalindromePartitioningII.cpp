#include <bits/stdc++.h>
using namespace std;

//Recursive
class Solution {
public:
    bool isPalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--; 
        }
        return true;
    }
    int f(int i,int &n,string &s){
        if(i==n)
            return 0;
        int minCost=1e9;
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                int cost=1+f(j+1,n,s);
                minCost=min(minCost,cost);
            }
        }
        return minCost;
    }
    int minCut(string &s) {
        int n=s.size();
        return f(0,n,s)-1;
    }
};

//Memoization
bool isPalindrome(string &s,int start,int end){
    while(start<end){
        if(s[start]!=s[end])
            return false;
        start++;
        end--; 
    }
    return true;
}
int f(int i,int &n,string &s,vector<int> &dp){
    if(i==n)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int minCost=1e9;
    for(int j=i;j<n;j++){
        if(isPalindrome(s,i,j)){
            int cost=1+f(j+1,n,s,dp);
            minCost=min(minCost,cost);
        }
    }
    return dp[i]=minCost;
}
int minCut(string &s) {
    int n=s.size();
    vector<int> dp(n,-1);
    return f(0,n,s,dp)-1;
}

//Tabulation
int minCut(string &s) {
    int n=s.size();
    vector<int> dp(n+1,0);
    // dp[n]=0; //base case
    for(int i=n-1;i>=0;i--){
        int minCost=1e9;
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                int cost=1+dp[j+1];
                minCost=min(minCost,cost);
            }
        }
        dp[i]=minCost;
    }
    return dp[0]-1;
}