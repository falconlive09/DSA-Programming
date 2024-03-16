#include <bits/stdc++.h>
using namespace std;
//Recursive
class Solution {
public:
    int f(int ind,int buy,vector<int> &prices,int fee){
        if(ind==prices.size())
            return 0;
        int profit=0;
        if(buy) //buy or not buy
            profit=max((-prices[ind]+f(ind+1,0,prices,fee)),f(ind+1,1,prices,fee));
        else //Selling with a -transaction charge or not sell 
            profit=max((prices[ind]-fee+f(ind+1,1,prices,fee)),f(ind+1,0,prices,fee));
        return profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        return f(0,1,prices,fee);
    }
};

//Memoization
int f(int ind,int buy,vector<int> &prices,int fee,vector<vector<int>> &dp){
    if(ind==prices.size())
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    int profit=0;
    if(buy) //buy or not buy
        profit=max((-prices[ind]+f(ind+1,0,prices,fee,dp)),f(ind+1,1,prices,fee,dp));
    else //Selling with a -transaction charge or not sell
        profit=max((prices[ind]-fee+f(ind+1,1,prices,fee,dp)),f(ind+1,0,prices,fee,dp));
    return dp[ind][buy]=profit;
}
int maxProfit(vector<int>& prices,int fee) {
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    return f(0,1,prices,fee,dp);
}

//Tabulation
int maxProfit(vector<int>& prices,int fee) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[n][0]=0,dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy) //buy or not buy
                profit=max((-prices[ind]+dp[ind+1][0]),dp[ind+1][1]);
            else //Selling with a -transaction charge or not sell
                profit=max((prices[ind]-fee+dp[ind+1][1]),dp[ind+1][0]);
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}

//General Optimisation
int maxProfit(vector<int>& prices,int fee) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[n][0]=0,dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--){
        int profit=0;
        //buy or not buy
        dp[ind][1]=max((-prices[ind]+dp[ind+1][0]),dp[ind+1][1]);
        //Selling with a -transaction charge or not sell
        dp[ind][0]=max((prices[ind]-fee+dp[ind+1][1]),dp[ind+1][0]); 
    }
    return dp[0][1];
}

//Space Optimisation (required for interviews)
int maxProfit(vector<int>& prices,int fee) {
    int n=prices.size();
    vector<int> ahead(2,0),curr(2,0);
    //ahead[0]=0,ahead[1]=0; Not needed Base Case as already initialised
    for(int ind=n-1;ind>=0;ind--){
        //buy or not buy
        curr[1]=max((-prices[ind]+ahead[0]),ahead[1]);
        //Selling with a -transaction charge or not sell
        curr[0]=max((prices[ind]-fee+ahead[1]),ahead[0]);

        ahead=curr;
    }
    return ahead[1];
}

//Same but with 4 variables
int maxProfit(vector<int>& prices,int fee) {
    int n=prices.size();
    int aheadNotBuy=0,aheadBuy=0,currBuy,currNotBuy; //Base Cases
    for(int ind=n-1;ind>=0;ind--){
        int profit=0;
        //Selling with a -transaction charge or not sell
        currNotBuy=max((prices[ind]-fee+aheadBuy),aheadNotBuy); //buy is 0 cond.
        currBuy=max((-prices[ind]+aheadNotBuy),aheadBuy); //buy is 1 cond.

        aheadBuy=currBuy;
        aheadNotBuy=currNotBuy;
    }
    return aheadBuy;
}