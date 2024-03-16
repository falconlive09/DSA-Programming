#include <bits/stdc++.h>
using namespace std;
//Prerequisite: See the 3rd problem
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1,0));
        //Base Cases not needed as already initialised as 0
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){ //cap need not start with 0 as we have already computed it
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
        return after[1][k];
    }
};

//Another approach

//Memoization
int f(int ind,int trans,int &k,vector<int> &prices,vector<vector<int>> &dp){
    if(ind==prices.size() || trans==2*k)
        return 0;
    if(dp[ind][trans]!=-1)
        return dp[ind][trans];
    int profit=0;
    if(trans%2==0) //buy or not buy
        profit=max((-prices[ind]+f(ind+1,trans+1,k,prices,dp)),f(ind+1,trans,k,prices,dp));
    else //Sell or not sell
        profit=max((prices[ind]+f(ind+1,trans+1,k,prices,dp)),f(ind+1,trans,k,prices,dp));
    return dp[ind][trans]=profit;
}
int maxProfit(int k,vector<int>& prices) {
    vector<vector<int>> dp(prices.size(),vector<int>(2*k,-1));
    return f(0,0,k,prices,dp); //trans start from 0 as it start from buy stage
}

//Tabulation
int maxProfit(int k,vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,0)); //used 2*k+1 for setting base case for trans==2*k
    //Base Case(already declared)
    /*
    for(int ind=0;ind<n;ind++){
        dp[ind][2*k]=0; //for trans==2*k on every index
    }
    */
    for(int ind=n-1;ind>=0;ind--){
        for(int trans=0;trans<=2*k-1;trans++){ //till 2*k-1 as for trans==2*k, base case has covered it
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
int maxProfit(int k,vector<int>& prices) {
    int n=prices.size();
    vector<int> after(2*k+1,0),curr(2*k+1,0); //used 2*k+1 for setting base case for trans==2*k
    for(int ind=n-1;ind>=0;ind--){
        for(int trans=0;trans<=2*k-1;trans++){ //till 2*k-1 as for trans==2*k, base case has covered it
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