#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int ans=1e9;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++) {
            if(mp.find(s[i])==mp.end()) mp[s[i]]=i;
            else    mp[s[i]]=1e9;
        }
        for(auto &it: mp){
            ans=min(ans,it.second);
        }
        return (ans==1e9)? -1 : ans;
    }
};