#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossible(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) //exactly one character difference as given in ques
            return false;
        int first=0;
        int second=0;
        while(first<s1.size()){
            if(s1[first]==s2[second] && second<s2.size()){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size())
            return true;
        return false;
    }
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp); //Sorting the array acc. to length
        //O(nlog n) for the sort
        int maxi=1;
        vector<int> dp(n,1); //Space Complexity -> O(n)
        for(int ind=0;ind<n;ind++){ //O(nxn)
            for(int prev_ind=0;prev_ind<ind;prev_ind++){ 
                //O(nxn x l(length of the max string))
                if(checkPossible(arr[ind],arr[prev_ind]) && 1+dp[prev_ind]>dp[ind]){ 
                    dp[ind]=1+dp[prev_ind];
                } 
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
            }
        }
        return maxi;
    }
};