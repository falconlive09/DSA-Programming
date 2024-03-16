#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int mini=1e9,start=0,count=mp.size();
        int i=0,j=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            if(count==0){
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                            if(j-i+1<mini){
                                mini=j-i+1;
                                start=i;
                            }
                        }
                    }
                    i++;
                } 
            }
            j++; 
        }
        if(mini==1e9)   return "";
        return s.substr(start,mini);
    }
};