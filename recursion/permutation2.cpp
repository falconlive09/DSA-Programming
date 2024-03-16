//Approach 1: Not using an extra map array
//No extra space utilised
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recurPermute(int ind,vector<int> &nums,vector<vector<int>> &ans)
    {
        //Time Complexity -> O(n! x n) 
        if(ind==nums.size())
        {
            ans.push_back(nums);    
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            recurPermute(ind+1,nums,ans);
            swap(nums[ind],nums[i]); //reswap after recursion
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0,nums,ans);
        return ans;
    }
};