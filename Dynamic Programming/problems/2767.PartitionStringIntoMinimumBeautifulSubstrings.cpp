#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the decimal
    // value of binary equivalent
    int number(string s, int i, int j){
        int ans = 0;
        for(int x=i;x<=j;x++){
            ans=ans*2+(s[x]-'0');
        }
        return ans;
    }
    bool isPowerOf5(int num) {
        if (num <= 0)   return false;
        while (num % 5 == 0)  num /= 5;
        return num == 1;
    }
    int f(int i,int &n,string &s){
        if(i==n)
            return 0;
        if(s[i]=='0')
            return 20;
        int minCost=20;
        for(int j=i;j<n;j++){
            int nos=number(s,i,j);
            if(isPowerOf5(nos)){
                int cost=1+f(j+1,n,s);
                minCost=min(minCost,cost);
            }
        }
        return minCost;
    }
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        int ans=f(0,n,s);
        if(ans>s.size())
            return -1;
        return ans;
    }
};

//Memoization

// Function to return the decimal
// value of binary equivalent
int number(string s, int i, int j){
    int ans = 0;
    for(int x=i;x<=j;x++){
        ans=ans*2+(s[x]-'0');
    }
    return ans;
}
bool isPowerOf5(int num) {
    if (num <= 0)   return false;
    while (num % 5 == 0)  num /= 5;
    return num == 1;
}
int f(int i,int &n,string &s,vector<int> &dp){
    if(i==n)
        return 0;
    if(s[i]=='0')
        return 20;
    if(dp[i]!=-1e9)
        return dp[i];
    int minCost=20;
    for(int j=i;j<n;j++){
        int nos=number(s,i,j);
        if(isPowerOf5(nos)){
            int cost=1+f(j+1,n,s,dp);
            minCost=min(minCost,cost);
        }
    }
    return dp[i]=minCost;
}
int minimumBeautifulSubstrings(string &s) {
    int n=s.size();
    vector<int> dp(n,-1e9);
    int ans=f(0,n,s,dp);
    if(ans>s.size())
        return -1;
    return ans;
}

//Tabulation
bool isPowerOf5(int num) {
    if(num<=0) 
        return false;
    while(num%5==0) 
        num/=5;
    return num==1;
}
int minimumBeautifulSubstrings(string s) {
    int n=s.size();
    vector<int> dp(n+1,20);  // Initialize with a large value initially
    dp[n]=0; //Base Case
    for (int i=n-1;i>=0;i--) {
        if(s[i]=='0') {
            dp[i]=20;  // Non-beautiful substrings have a higher cost
            continue;
        }
        int nos=0;
        for(int j=i;j<n;j++) {
            nos=nos*2+(s[j]-'0');
            if(isPowerOf5(nos)){
                dp[i]=min(dp[i],1+dp[j+1]);
            }
        }
    }
    if(dp[0]>n)
        return -1;
    return dp[0];
}