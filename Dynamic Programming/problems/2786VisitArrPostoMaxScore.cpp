#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long f(int ind,int prev,int x,vector<int>&nums,vector<vector<long long>> &dp)
    {
        if(ind>=nums.size())
            return 0;
        if(dp[ind][prev]!=-1)
            return dp[ind][prev];
        long long notTake=f(ind+1,prev,x,nums,dp);
        long long take=-1e9;
        if((nums[ind]%2==0 && prev==0) || (nums[ind]%2==1 && prev==1))
        {
            take=nums[ind]+f(ind+1,nums[ind]%2,x,nums,dp);
        }
        else
        {
            take=nums[ind]-x+f(ind+1,nums[ind]%2,x,nums,dp);
        }
        return dp[ind][prev]=max(take,notTake);
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        return nums[0]+f(1,nums[0]%2,x,nums,dp);
    }
};