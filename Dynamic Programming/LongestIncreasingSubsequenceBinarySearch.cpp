#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){ //if this guy is greater than the last guy
                temp.push_back(nums[i]);
                len++;
            }
            else{ //binary search
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        //return temp.size();
        return len;
    }
};