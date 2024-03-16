#include <bits/stdc++.h>
using namespace std;
//Recursive
class Solution {
public:
    int f(int ind,int buy,int cap,vector<int> &prices){
        if(cap==0)
            return 0;
        if(ind==prices.size())
            return 0;
        int profit=0;
        if(buy) //buy or not buy
            profit=max((-prices[ind]+f(ind+1,0,cap,prices)),f(ind+1,1,cap,prices));
        else //Sell or not sell
            profit=max((prices[ind]+f(ind+1,1,cap-1,prices)),f(ind+1,0,cap,prices));
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return f(0,1,2,prices);
    }
};

//Memoization
int f(int ind,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp){
    if(cap==0)
        return 0;
    if(ind==prices.size())
        return 0;
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
    int profit=0;
    if(buy) //buy or not buy
        profit=max((-prices[ind]+f(ind+1,0,cap,prices,dp)),f(ind+1,1,cap,prices,dp));
    else //Sell or not sell
        profit=max((prices[ind]+f(ind+1,1,cap-1,prices,dp)),f(ind+1,0,cap,prices,dp));
    return dp[ind][buy][cap]=profit;
}
int maxProfit(vector<int>& prices) {
    vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,1,2,prices,dp);
}

//Tabulation
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //Base Cases not needed as already initialised as 0
    /* 
    for(int ind=0;ind<n;ind++){
        for(int buy=0;buy<=1;buy++)
            dp[ind][buy][0]=0; //for cap==0
    }
    for(int buy=0;buy<=1;buy++){
        for(int cap=0;cap<=2;cap++)
            dp[n][buy][0]=0; //for ind==n
    }
    */
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){ //cap need not start with 0 as we have already computed it
                int profit=0;
                if(buy) //buy or not buy
                    profit=max((-prices[ind]+dp[ind+1][0][cap]),dp[ind+1][1][cap]);
                else //Sell or not sell
                    profit=max((prices[ind]+dp[ind+1][1][cap-1]),dp[ind+1][0][cap]);
                dp[ind][buy][cap]=profit;
            }
        }
    }
    return dp[0][1][2];
}

//Space Optimisation to 2D Dp
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> after(2,vector<int>(3,0));
    vector<vector<int>> curr(2,vector<int>(3,0));
    //Base Cases not needed as already initialised as 0
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){ //cap need not start with 0 as we have already computed it
                int profit=0;
                if(buy) //buy or not buy
                    profit=max((-prices[ind]+after[0][cap]),after[1][cap]);
                else //Sell or not sell
                    profit=max((prices[ind]+after[1][cap-1]),after[0][cap]);
                curr[buy][cap]=profit;
            }
            after=curr;
        }
    }
    return after[1][2];
}

//another approach (nx4)
//Memoization
int f(int ind,int trans,vector<int> &prices,vector<vector<int>> &dp){
    if(ind==prices.size() || trans==4)
        return 0;
    if(dp[ind][trans]!=-1)
        return dp[ind][trans];
    int profit=0;
    if(trans%2==0) //buy or not buy
        profit=max((-prices[ind]+f(ind+1,trans+1,prices,dp)),f(ind+1,trans,prices,dp));
    else //Sell or not sell
        profit=max((prices[ind]+f(ind+1,trans+1,prices,dp)),f(ind+1,trans,prices,dp));
    return dp[ind][trans]=profit;
}
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(),vector<int>(4,-1));
    return f(0,0,prices,dp); //trans start from 0 as it start from buy stage
}

//Tabulation
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(5,0)); //used 5 for setting base case for trans==4 
    //Base Case(already declared)
    /*
    for(int ind=0;ind<n;ind++){
        dp[ind][4]=0; //for trans==4 on every index
    }
    */
    for(int ind=n-1;ind>=0;ind--){
        for(int trans=0;trans<=3;trans++){ //till 3 as for trans==4 base case has covered it
            int profit=0;
            if(trans%2==0) //buy or not buy
                profit=max((-prices[ind]+dp[ind+1][trans+1]),dp[ind+1][trans]);
            else //Sell or not sell
                profit=max((prices[ind]+dp[ind+1][trans+1]),dp[ind+1][trans]);
            dp[ind][trans]=profit;
        }
    }
    return dp[0][0];
}

//Space Optimisation(remember this)
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> after(5,0),curr(5,0); //used 5 for setting base case for trans==4 
    for(int ind=n-1;ind>=0;ind--){
        for(int trans=0;trans<=3;trans++){ //as for trans==4 base case has covered it
            int profit=0;
            if(trans%2==0) //buy or not buy
                profit=max((-prices[ind]+after[trans+1]),after[trans]);
            else //Sell or not sell
                profit=max((prices[ind]+after[trans+1]),after[trans]);
            curr[trans]=profit;
        }
        after=curr;
    }
    return after[0];
}