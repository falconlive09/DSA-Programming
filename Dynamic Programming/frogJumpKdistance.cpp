#include <bits/stdc++.h> 
using namespace std;
//TABULATION
int frogKJump(int n, int k, vector<int> &heights){
    vector<int> dp(n,0); 
    dp[0]=0;
    for(int i=1;i<n;i++){
        int minSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if((i-j)>=0){
                int jump=dp[i-j]+abs(heights[i]-heights[i-j]);
                minSteps=min(minSteps,jump);
            }
        }
        dp[i]=minSteps;
    }
    return dp[n-1];
}
int main(){
    vector<int> heights{30,10,60,10,60,50};
    int n=heights.size();
    int k=2;
    cout<<frogKJump(n,k,heights);
}