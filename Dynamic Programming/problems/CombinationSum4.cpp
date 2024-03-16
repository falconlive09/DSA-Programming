//extension to coin change II
#include<bits/stdc++.h>
using namespace std;

//Recursive
class Solution {
public:
    int f(int ind,int target,vector<int> &nums)
    {   
        if(target==0)
            return 1;
        if (ind < 0 || target < 0) 
            return 0; // No valid combination possible
        int notTake=0+f(ind-1,target,nums);
        int take=0;
        if(nums[ind]<=target)
            take=f(nums.size()-1,target-nums[ind],nums);
        return take+notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,target,nums);
    }
};

//Memoization
int f(int ind,int target,vector<int> &nums,vector<int> &dp)
{   
    if(target==0)
        return 1;
    if (ind < 0 || target < 0) 
        return 0; // No valid combination possible
    if(dp[target]!=-1)
        return dp[target];
    int notTake=0+f(ind-1,target,nums,dp);
    int take=0;
    if(nums[ind]<=target)
        take=f(nums.size()-1,target-nums[ind],nums,dp);
    return dp[target]=take+notTake;
}
int combinationSum4(vector<int>& nums, int target) {
    int n=nums.size();
    vector<int> dp(target+1,-1);
    return f(nums.size()-1,target,nums,dp);
}

//Tabulation
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1; //base case 
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                unsigned int notTake=dp[i]; //i have target
                unsigned int take=0;
                if(nums[j]<=i)
                    take=dp[i-nums[j]];
                dp[i]=take+notTake;
            }
        }
        return dp[target];
    }
};