#include<bits/stdc++.h>
using namespace std;

//Recursive
class Solution {
public:
    bool f(int ind,string &s,unordered_set<string>&dict)
    {
        if(ind==s.size())
            return true;
        string st="";
        for(int i=ind;i<s.size();i++){
            st=s.substr(ind,i+1-ind);
            if(dict.find(st)!=dict.end() && f(i+1,s,dict))
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        return f(0,s,dict);
    }
};

//Memoization
bool f(int ind,string &s,unordered_set<string>&dict,vector<int> &dp)
{
    if(ind==s.size())
        return true;
    if(dp[ind]!=-1)
        return dp[ind];
    string st="";
    for(int i=ind;i<s.size();i++){
        st=s.substr(ind,i+1-ind);
        if(dict.find(st)!=dict.end() && f(i+1,s,dict,dp)){
            dp[ind]=1;
            return dp[ind];
        }
    } 
    dp[ind]=0;
    return dp[ind];
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string>dict(wordDict.begin(),wordDict.end());
    vector<int> dp(s.length(),-1);
    return f(0,s,dict,dp);
}

//Tabulation
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n=s.size();
    vector<int> dp(n+1,0); 
    dp[n]=1; //Base Case
    string st="";
    for(int ind=n-1;ind>=0;ind--){
        for(int j=ind;j<n;j++){
            st=s.substr(ind,j+1-ind);
            if(dict.find(st)!=dict.end() && dp[j+1]){
                dp[ind]=1;
                break; 
            }
        }
    }
    return dp[0];
}