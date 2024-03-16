#include<bits/stdc++.h>
using namespace std;
//CodeStudio problem
int kDistinctChars(int &k, string &s)
{
    int n=s.size();
    unordered_map<char,int> mp;
    int i=0,j=0;
    int maxi=-1;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()<k){
            maxi=max(maxi,(j-i+1));
            j++;
        }
        else if(mp.size()==k){
            maxi=max(maxi,(j-i+1));
            j++;
        } 
        else if(mp.size()>k){
            while(mp.size()>k){
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