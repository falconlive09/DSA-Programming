#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[n][0]=0,dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy) //buy or not buy
                    profit=max((-prices[ind]+dp[ind+1][0]),dp[ind+1][1]);
                else //Sell or not sell
                //ind+2 as cannot buy on next day after selling
                    profit=max((prices[ind]+dp[ind+2][1]),dp[ind+1][0]); 
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};

//General Optimisation
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    dp[n][0]=0,dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--){
        int profit=0;
        //buy or not buy
        dp[ind][1]=max((-prices[ind]+dp[ind+1][0]),dp[ind+1][1]);
        //Sell or not sell
        //ind+2 as cannot buy on next day after selling
        dp[ind][0]=max((prices[ind]+dp[ind+2][1]),dp[ind+1][0]); 
    }
    return dp[0][1];
}
//Space Optimisation
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> front2(2,0),front1(2,0),curr(2,0);
    for(int ind=n-1;ind>=0;ind--){
        int profit=0;
        //buy or not buy
        curr[1]=max((-prices[ind]+front1[0]),front1[1]);
        //Sell or not sell
        //ind+2 as cannot buy on next day after selling
        curr[0]=max((prices[ind]+front2[1]),front1[0]); 

        front2=front1;
        front1=curr;
    }   
    return curr[1];
}