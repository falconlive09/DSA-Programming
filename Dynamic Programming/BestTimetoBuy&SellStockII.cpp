#include <bits/stdc++.h>
using namespace std;
//Recursive
class Solution {
public:
    int f(int ind,int buy,vector<int> &prices){
        if(ind==prices.size())
            return 0;
        int profit=0;
        if(buy) //buy or not buy
            profit=max((-prices[ind]+f(ind+1,0,prices)),f(ind+1,1,prices));
        else //Sell or not sell
            profit=max((prices[ind]+f(ind+1,1,prices)),f(ind+1,0,prices));
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return f(0,1,prices);
    }
};

//Memoization
int f(int ind,int buy,vector<int> &prices,vector<vector<int>> &dp){
    if(ind==prices.size())
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    int profit=0;
    if(buy) //buy or not buy
        profit=max((-prices[ind]+f(ind+1,0,prices,dp)),f(ind+1,1,prices,dp));
    else //Sell or not sell
        profit=max((prices[ind]+f(ind+1,1,prices,dp)),f(ind+1,0,prices,dp));
    return dp[ind][buy]=profit;
}
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    return f(0,1,prices,dp);
}

//Tabulation
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[n][0]=0,dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy) //buy or not buy
                profit=max((-prices[ind]+dp[ind+1][0]),dp[ind+1][1]);
            else //Sell or not sell
                profit=max((prices[ind]+dp[ind+1][1]),dp[ind+1][0]);
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}

//Space Optimisation (required for interviews)
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> ahead(2,0),curr(2,0);
    ahead[0]=0,ahead[1]=0; //Base Case
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy) //buy or not buy
                profit=max((-prices[ind]+ahead[0]),ahead[1]);
            else //Sell or not sell
                profit=max((prices[ind]+ahead[1]),ahead[0]);
            
            curr[buy]=profit;
        }
        ahead=curr;
    }
    return ahead[1];
}

//Same but with 4 variables
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int aheadNotBuy=0,aheadBuy=0,currBuy,currNotBuy; //Base Cases
    for(int ind=n-1;ind>=0;ind--){
        int profit=0;
        currNotBuy=max((prices[ind]+aheadBuy),aheadNotBuy); //buy is 0 cond.
        currBuy=max((-prices[ind]+aheadNotBuy),aheadBuy); //buy is 1 cond.

        aheadBuy=currBuy;
        aheadNotBuy=currNotBuy;
    }
    return aheadBuy;
}