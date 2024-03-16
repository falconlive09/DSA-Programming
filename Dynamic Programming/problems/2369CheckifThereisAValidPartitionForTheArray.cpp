#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(int ind,vector<int> &nums,int &n){
        if(ind==n)
            return true;
        bool cond1=false,cond2=false,cond3=false;
        if(ind+1<n && nums[ind]==nums[ind+1])
            cond1=f(ind+2,nums,n);
        if(ind+2<n && nums[ind]==nums[ind+1] && nums[ind]==nums[ind+2])
            cond2=f(ind+3,nums,n);
        if(ind+2<n && 1+nums[ind]==nums[ind+1] && 1+nums[ind+1]==nums[ind+2])
            cond3=f(ind+3,nums,n);
        return cond1 || cond2 || cond3;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        return f(0,nums,n);
    }
};

//Memoization
bool f(int ind,vector<int> &nums,vector<int> &dp,int &n){
    if(ind==n)
        return true;
    if(dp[ind]!=-1)
        return dp[ind];
    bool cond1=false,cond2=false,cond3=false;
    if(ind+1<n && nums[ind]==nums[ind+1])
        cond1=f(ind+2,nums,dp,n);
    if(ind+2<n && nums[ind]==nums[ind+1] && nums[ind]==nums[ind+2])
        cond2=f(ind+3,nums,dp,n);
    if(ind+2<n && 1+nums[ind]==nums[ind+1] && 1+nums[ind+1]==nums[ind+2])
        cond3=f(ind+3,nums,dp,n);
    return dp[ind]=cond1 || cond2 || cond3;
}
bool validPartition(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,-1);
    return f(0,nums,dp,n);
}