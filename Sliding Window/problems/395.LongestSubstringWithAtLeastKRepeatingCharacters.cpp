#include <bits/stdc++.h>
using namespace std;
//not working
class Solution {
public:
    int longestSubstring(string &s, int &k) {
        int n=s.size();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int maxi=0;
        while(j<n){
            mp[s[j]]++;
            for(auto t:mp)
            {
                if(t.second<k)continue;
            }
            maxi=max(maxi,j-i+1);
            while(i<j && mp[s[i]]>0)
            {
                mp[s[i]]--;
                i++;
            }
            if(mp[s[j]]<=0)
            {
                mp.erase(mp[s[j]]);
            }
        }
        return maxi;
    }
};