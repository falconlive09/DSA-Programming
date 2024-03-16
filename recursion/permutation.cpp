//Approach 1: Using an extra map array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recurPermute(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans,int *freq)
    {
        if(ds.size()==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermute(ds,nums,ans,freq);
                freq[i]=0; //returning from recursion umark the element from map
                ds.pop_back(); //removing the element after recursion
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            freq[i]=0;
        }
        recurPermute(ds,nums,ans,freq);
        return ans;
    }
};