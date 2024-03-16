#include <bits/stdc++.h>
using namespace std;
//using map
int lengthOfLongestSubstring(string &s) {
    int n=s.size();
    unordered_map<char,int> mp;
    int i=0,j=0;
    int maxi=0;
    while(j<n){
        mp[s[j]]++;
        // if(mp.size()>(j-i+1))  this condition will never hit
        //     j++;
        if(mp.size()==(j-i+1)){ //all characters in the window should be unique
            maxi=max(maxi,(j-i+1));
            j++;
        }  
        else if(mp.size()<(j-i+1)){ //if window size is more then there must be a repeating charcter in map
            while(mp.size()<(j-i+1)){ 
                mp[s[i]]--;
                if(mp[s[i]]==0) //count of character gets 0 delete it from map
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
}

//using set
class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int n=s.size();
        unordered_set<char> unique;
        int i=0,j=0;
        int maxi=0;
        while(j<n){
            if(unique.find(s[j])==unique.end()){
                unique.insert(s[j]);
                maxi=max(maxi,(j-i+1));
                j++;
            }
            else{ 
            //the repitive character gets detected, we have to erase characters from the ith pos
                unique.erase(s[i]); 
                i++;
            }
        }
        return maxi;
    }
};