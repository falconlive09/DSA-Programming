#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& nums, int n){
    vector<int> dp1(n,1);
    for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(nums[prev_ind]<nums[ind] && 1+dp1[prev_ind]>dp1[ind]){
                dp1[ind]=1+dp1[prev_ind];
            } 
        }
    }
    vector<int> dp2(n,1);
    int maxi=1;
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=n-1;prev_ind>ind;prev_ind--){
            if(nums[prev_ind]<nums[ind] && 1+dp2[prev_ind]>dp2[ind]){
                dp2[ind]=1+dp2[prev_ind];
            } 
        }
        maxi=max(maxi,dp1[ind]+dp2[ind]-1);
    }
    // int maxi=1;
    // for(int i=0;i<n;i++){
    //     maxi=max(maxi,dp1[i]+dp2[i]-1);
    // }
    return maxi;
}   
