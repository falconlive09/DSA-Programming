#include <bits/stdc++.h>
using namespace std;

//optimal T.C.-> O(N)+O(2N)~ O(3N) S.C.-> O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)    return 0;
        unordered_set<int> s;
        for(auto &i:nums) {
            s.insert(i);
        }
        int longest=1;
        int cnt=0;
        for(auto &i:s) {
            if(s.find(i-1)==s.end()) { //starting point
                cnt=1;
                int x=i;
                while(s.find(x+1)!=s.end()) {
                    x=x+1;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};