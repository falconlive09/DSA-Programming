//Not passing on test case 22
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recursion(int ind,vector<int> nums, vector<vector<int> > &ans) {
        if (ind == nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            if (ind != i && nums[ind] == nums[i]) continue;
            swap(nums[ind], nums[i]);
            recursion(i+1,nums,ans);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> >ans;
        recursion(0,nums, ans);
        return ans;
    }
};