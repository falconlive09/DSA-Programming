#include <bits/stdc++.h> 
using namespace std;

int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<int> prev(k+1,0),curr(k+1);  
    if(arr[0]==0)
        prev[0]=2; //at index 0, we can either pick or not pick
    else
        prev[0]=1; //at index 0 the sum is 0 but arr[0] is not 0 so not pick 
    //arr[0]=0
    if(arr[0]!=0 && arr[0]<=k) //if arr[0] is 0 then we have already considered it which is =2
        prev[arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=k;sum++){
            int notPick=prev[sum];
            int pick=0;
            if(arr[ind]<=sum)
                pick=prev[sum-arr[ind]];
            curr[sum]=(notPick+pick);
        }
        prev=curr;
    }
    return prev[k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(auto &it:arr)
        totSum+=it;
    if(totSum-d<0 || (totSum-d)%2)
        return 0;
    return findWays(arr,(totSum-d)/2);
}
int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n,target,arr);
}