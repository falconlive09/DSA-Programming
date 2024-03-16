#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //memoization
    int f(vector<int> &cost,int ind,vector<int> &dp)
    {
        if(ind==0 || ind==1)
            return 0;
        if(dp[ind]!=-1) 
            return dp[ind];
        return dp[ind]=min(f(cost,ind-1,dp)+cost[ind-1],f(cost,ind-2,dp)+cost[ind-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return f(cost,cost.size(),dp);
    }
    //Tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        dp[0]=dp[1]=0;
        for(int ind=2;ind<=cost.size();ind++)
        {
            dp[ind]=min(dp[ind-1]+cost[ind-1],dp[ind-2]+cost[ind-2]);
        }
        return dp[cost.size()-1];
    }
    //space optimization
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2=0,prev=0;
        for(int ind=2;ind<=cost.size();ind++)
        {
            int curi=min(prev+cost[ind-1],prev2+cost[ind-2]);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};