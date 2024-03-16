#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int,vector<int>,greater<int>>n1;

        for(int i=0;i<nums1.size();i++)
        {
            n1.push(nums1[i]);
        }
        priority_queue<int,vector<int>,greater<int>>n2;
        for(int i=0;i<nums2.size();i++)
        {
            n2.push(nums2[i]);
        }
        vector<vector<int>>result;
        
    }
};
