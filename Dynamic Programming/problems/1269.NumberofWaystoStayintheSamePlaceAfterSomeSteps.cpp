#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int f(int ind,int steps,int &arrLen) {
        if(ind==0){
            if(steps==0)
                return 1;
        }
        if(steps==0)
            return 0;
        int left=0,right=0,stay=0;
        if(ind>=0 && ind<arrLen){
            left=f(ind-1,steps-1,arrLen)%mod;
            stay=f(ind,steps-1,arrLen)%mod;
            right=f(ind+1,steps-1,arrLen)%mod;
        }
        return (left+right+stay)%mod;
        
    }
    int numWays(int &steps, int &arrLen) {
        return f(0,steps,arrLen);
    }
};

//Memoization