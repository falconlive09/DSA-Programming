#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    void findCombinationSum(int ind,int target,vector<int>&arr,vector<vector<int>> &ans,vector<int>&ds)
    {
        if(ind==arr.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        //picking up the element 
        if(arr[ind]<=target)
        {
            ds.push_back(arr[ind]);
            findCombinationSum(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        findCombinationSum(ind+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        findCombinationSum(0,target,candidates,ans,ds);
        return ans;
    }
};