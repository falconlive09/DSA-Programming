#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        vector<int> dp(n,1),count(n,1);
        for(int ind=0;ind<n;ind++){
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[prev_ind]<nums[ind] && 1+dp[prev_ind]>dp[ind]){
                    dp[ind]=1+dp[prev_ind];
                    //inherit dont add
                    count[ind]=count[prev_ind];
                } 
                else if(nums[prev_ind]<nums[ind] && 1+dp[prev_ind]==dp[ind]){
                    //increase the count
                    count[ind]+=count[prev_ind];
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
            }
        }
        int noLis=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)
                noLis+=count[i];
        }
        return noLis;
    }
};