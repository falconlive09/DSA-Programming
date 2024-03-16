#include <bits/stdc++.h> 
using namespace std;
//Using Recursion
int f(int ind,vector<int> &nums)
{
    if(ind==0)  return nums[ind];
    if(ind<0)   return 0;

    int pick=nums[ind]+f(ind-2,nums);
    int notPick=0+f(ind-1,nums);

    return max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    return f(n-1,nums);
}

//Using 1D dp array(Memoization)
int f(int ind,vector<int> &nums,vector<int> &dp)
{
    if(ind==0)  return nums[ind];
    if(ind<0)   return 0;
    if(dp[ind]!=-1) return dp[ind];

    int pick=nums[ind]+f(ind-2,nums,dp);
    int notPick=0+f(ind-1,nums,dp);

    return dp[ind]=max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp);
}

//space optimized solution
int maximumNonAdjacentSum(vector<int> &nums){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=0;i<n;i++){
        int take=nums[i];
        if(i>1) take+=prev2;
        
        int notTake=0+prev;
        int curi=max(take,notTake);
        prev2=prev;
        prev=curi;
    }
    return prev;
}