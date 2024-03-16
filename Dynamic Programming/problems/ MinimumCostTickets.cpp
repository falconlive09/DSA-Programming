#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind,vector<int> &day, vector<int> &cost)		
    {
        int n = day.size();
        if(ind>=n)   return 0;
        int cost_day = cost[0] + f(ind+1,day,cost);
        
        int i;
        for(i =ind ; i<n && day[i]<day[ind]+7 ; i++);
        int cost_week = cost[1] + f(i,day,cost);
        
        for(i=ind ; i<n && day[i]<day[ind]+30 ; i++); 
        int cost_month = cost[2] + f(i,day, cost);      
        
        return min(cost_day, min(cost_week , cost_month));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {        
        return f(0,days,costs);
    }
};

//Memoization
int f(int ind,vector<int> &day, vector<int> &cost,vector<int> &dp){
    int n=day.size();
    if(ind>=n)   
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int cost_day=cost[0]+f(ind+1,day,cost,dp);
    
    int i;
    for(i=ind;i<n && day[i]<day[ind]+7;i++);
    int cost_week=cost[1]+f(i,day,cost,dp);
    
    for(i=ind;i<n && day[i]<day[ind]+30;i++); 
    int cost_month=cost[2]+f(i,day,cost,dp);      
    
    return dp[ind]=min(cost_day,min(cost_week,cost_month));
}
int mincostTickets(vector<int>& days, vector<int>& costs){        
    vector<int>dp(days.size()+1,-1);
    return f(0,days,costs,dp);
}

//Tabulation
int mincostTickets(vector<int>& days, vector<int>& costs){        
    int n=days.size();
    vector<int>dp(n+1,1e9);
    dp[n]=0;
    for(int ind=n-1;ind>=0;ind--){
        int cost_day=costs[0]+dp[ind+1];
    
        int i;
        for(i=ind;i<n && days[i]<days[ind]+7;i++);
        int cost_week=costs[1]+dp[i];
        
        for(i=ind;i<n && days[i]<days[ind]+30;i++); 
        int cost_month=costs[2]+dp[i];     
        
        dp[ind]=min(cost_day,min(cost_week,cost_month));
    }
    return dp[0];
}