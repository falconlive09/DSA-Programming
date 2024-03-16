#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int>mp;
        vector<int> nge;
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && st.top() < nums2[i%n]) {
                st.pop();
            }
            if(st.empty()) mp[nums2[i%n]]=-1;
            else mp[nums2[i%n]]=st.top();
            st.push(nums2[i%n]);
        }
        for(int i=0;i<nums1.size();i++) {
            nge.push_back(mp[nums1[i]]);
        }
        return nge;
    }
};