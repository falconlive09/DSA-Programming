#include <bits/stdc++.h>
using namespace std;

//Recursive
class Solution {
public:
    int f(int i,int j,vector<int> &arr)
    {
        if(i>j)
            return 0;
        int maxi=-1e9;
        for(int ind=i;ind<=j;ind++){
            int cost=arr[i-1]*arr[ind]*arr[j+1]+f(i,ind-1,arr)+f(ind+1,j,arr);
            maxi=max(maxi,cost);
        }
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return f(1,n,nums); 
    }
};

//Memoization
int f(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int maxi=-1e9;
    for(int ind=i;ind<=j;ind++){
        int cost=arr[i-1]*arr[ind]*arr[j+1]+f(i,ind-1,arr,dp)+f(ind+1,j,arr,dp);
        maxi=max(maxi,cost);
    }
    return dp[i][j]=maxi;
}
int maxCoins(vector<int>& nums) {
    int n=nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(1,n,nums,dp); 
}

//Tabulation
int maxCoins(vector<int>& nums) {
    int n=nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){ //can also start from j=1 to j<=n
            if(i>j)
                continue;
            int maxi=-1e9;
            for(int ind=i;ind<=j;ind++){
                int cost=nums[i-1]*nums[ind]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
                maxi=max(maxi,cost);
            }
            dp[i][j]=maxi;
        }
    }
    return dp[1][n];
}