#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int maxi=0;
        while(j<n){
            mp[s[j]]++;
            // if(mp.size()>(j-i+1))  this condition will never hit 
            //     j++;
            if(mp.size()<(j-i+1)){ //if window size is more then there must be a repeating charcter in map
                while(mp.size()<(j-i+1)){ 
                    mp[s[i]]--;
                    if(mp[s[i]]==0) //count of character gets 0 delete it from map
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
            else{ //all characters in the window should be unique
                maxi=max(maxi,(j-i+1));
                j++;
            }
        }
        return maxi;
    }
};