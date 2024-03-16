#include <bits/stdc++.h>
using namespace std;
//Recursive
class Solution {
public:
    int f(int ind,int &n,vector<int>& arr, int &k){
        if(ind==n)
            return 0;
        int maxi=-1e9,maxSum=-1e9,len=0;
        for(int j=ind;j<ind+k && j<n;j++){
            len++;  
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi)+f(j+1,n,arr,k);
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int &k) {
        int n=arr.size();
        return f(0,n,arr,k);
    }
};

//Memoization
int f(int ind,int &n,vector<int>& arr, int &k,vector<int> &dp){
    if(ind==n)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int maxi=-1e9,maxSum=-1e9,len=0;
    for(int j=ind;j<ind+k && j<n;j++){
        len++;  
        maxi=max(maxi,arr[j]);
        int sum=(len*maxi)+f(j+1,n,arr,k,dp);
        maxSum=max(maxSum,sum);
    }
    return dp[ind]=maxSum;
}
int maxSumAfterPartitioning(vector<int>& arr, int &k) {
    int n=arr.size();
    vector<int> dp(n,-1);
    return f(0,n,arr,k,dp);
}

//Tabulation
int maxSumAfterPartitioning(vector<int>& arr, int &k) {
    int n=arr.size();
    vector<int> dp(n+1,0); //base case covered
    for(int ind=n-1;ind>=0;ind--){
        int maxi=-1e9,maxSum=-1e9,len=0;
        for(int j=ind;j<ind+k && j<n;j++){
            len++;  
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi)+f(j+1,n,arr,k,dp);
            maxSum=max(maxSum,sum);
        }
        dp[ind]=maxSum;
    }
    return dp[0];
}