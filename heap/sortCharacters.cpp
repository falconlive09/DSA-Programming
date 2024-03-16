#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s)
            mp[ch]++;
        priority_queue<pair<int,char>>pq;
        for(auto c:mp)
        {
            pq.push({c.second,c.first});
        }
        string str="";
        while(!pq.empty())
        {
           str.append(pq.top().first,pq.top().second);
           pq.pop();
        }
        return str;
    }
};