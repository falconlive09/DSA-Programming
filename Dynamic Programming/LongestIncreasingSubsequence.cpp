#include <bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int f(int ind,int prev_ind,vector<int>& nums,vector<vector<int>> &dp){
        if(ind==nums.size())
            return 0;
        if(dp[ind][prev_ind+1]!=-1)
            return dp[ind][prev_ind+1];
        int len=0+f(ind+1,prev_ind,nums,dp); //NotTake
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
            len=max(len,1+f(ind+1,ind,nums,dp)); //Take
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};

//Tabulation
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //Base Case defined with initialisation
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len=0+dp[ind+1][prev_ind+1]; //Coordinate shift with prev_ind
            if(prev_ind==-1 || nums[ind]>nums[prev_ind])
                len=max(len,1+dp[ind+1][ind+1]); //Coordinate shift with prev_ind
            dp[ind][prev_ind+1]=len;
        }
    }
    return dp[0][-1+1];
}

//Space Optimisation
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> next(n+1,0),curr(n+1,0);
    //Base Case defined with initialisation
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len=0+next[prev_ind+1]; //Coordinate shift with prev_ind
            if(prev_ind==-1 || nums[ind]>nums[prev_ind])
                len=max(len,1+next[ind+1]); //Coordinate shift with prev_ind
            curr[prev_ind+1]=len;
        }
        next=curr;
    }   
    return next[-1+1];
}

//Another Approach
int lengthOfLIS(vector<int>& nums) {
    //O(nxn)
    int n=nums.size();
    int maxi=1;
    vector<int> dp(n,1);
    for(int ind=0;ind<n;ind++){
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(nums[prev_ind]<nums[ind])
                dp[ind]=max(1+dp[prev_ind],dp[ind]);
        }
        maxi=max(maxi,dp[ind]);
    }
    return maxi;
}

//Printing the LIS
int lengthOfLIS(vector<int>& nums) {   
    //O(nxn)
    int n=nums.size();
    int maxi=1;
    int lastIndex=0;
    vector<int> dp(n,1),hash(n);
    for(int ind=0;ind<n;ind++){
        hash[ind]=ind;
        for(int prev_ind=0;prev_ind<ind;prev_ind++){
            if(nums[prev_ind]<nums[ind] && 1+dp[prev_ind]>dp[ind]){
                dp[ind]=1+dp[prev_ind];
                hash[ind]=prev_ind;
            } 
        }
        if(dp[ind]>maxi){
            maxi=dp[ind];
            lastIndex=ind; 
        }
    }
    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while (hash[lastIndex]!=lastIndex){ 
        lastIndex=hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    for(auto it: temp){
        cout<<it<<" ";
    }
    cout<<"\n";
    return maxi;
}