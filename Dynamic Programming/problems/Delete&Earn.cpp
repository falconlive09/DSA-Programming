//not working
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind, vector<int>& nums, unordered_map<int, int>& mp) {
        if (ind < 0) return 0;
        if (mp.find(nums[ind]) == mp.end())
            return 0;

        int pick = nums[ind] * mp[nums[ind]] + f(ind - 2, nums, mp);
        int notPick = f(ind - 1, nums, mp);

        return max(pick, notPick);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        return f(n - 1, nums, mp);
    }
};