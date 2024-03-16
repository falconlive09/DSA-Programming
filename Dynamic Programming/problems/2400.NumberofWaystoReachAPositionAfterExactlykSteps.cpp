#include <bits/stdc++.h>
using namespace std;

//Memoization
class Solution {
public:
    int mod=1e9+7;
    int f(int currPos, int steps, int &endPos, int &k, vector<vector<int>> &dp) {
        if(currPos==endPos){
            if(steps==k)
                return 1;
        }
        if(steps==k)
            return 0;
        if(dp[currPos][steps]!=-1)
            return dp[currPos][steps];
        int left=0,right=0;
        left+=f(currPos-1,steps+1,endPos,k,dp)%mod;
        right+=f(currPos+1,steps+1,endPos,k,dp)%mod;
        return dp[currPos][steps]=(left+right)%mod;
    }
    int numberOfWays(int &startPos, int &endPos, int &k) {
        int maxPos=max(abs(startPos),abs(endPos))+k;
        vector<vector<int>> dp(2*maxPos+1,vector<int>(k+1,-1));
        int newEndPos=endPos+maxPos;
        return f(startPos+maxPos,0,newEndPos,k,dp);
    }
};