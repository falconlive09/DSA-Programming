#include <bits/stdc++.h>
using namespace std;
//Use of longest bitonic subsequence
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,1);
        for(int ind=0;ind<n;ind++){
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[prev_ind]<nums[ind] && 1+dp1[prev_ind]>dp1[ind]){
                    dp1[ind]=1+dp1[prev_ind];
                } 
            }
        }
        vector<int> dp2(n,1);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=n-1;prev_ind>ind;prev_ind--){
                if(nums[prev_ind]<nums[ind] && 1+dp2[prev_ind]>dp2[ind]){
                    dp2[ind]=1+dp2[prev_ind];
                } 
            }
        }
        int maxi=0;
        // for(int i=0;i<n;i++){
        //     cout<<dp1[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<n;i++){
        //     cout<<dp2[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<n;i++){
        //     cout<<dp1[i]+dp2[i]-1<<" ";
        // }
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1) //we want strictly increasing first then strictly          decreasing
                maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        return n-maxi;
    }
};