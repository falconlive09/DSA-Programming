//fibonacci using 1D dynamic array
#include<bits/stdc++.h>
using namespace std;
//memoization
int f(int n, vector<int> &dp)
{
    if(n<=1)    
        return n;
    if(dp[n]!=-1) //step 2 
        return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp); //step 1
}
//tabulation Time Complexity: O(N)
//           Space Complexity: O(N)
int f2(int n, vector<int> &dp)
{
    dp[0]= 0;
    dp[1]= 1;
  
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }
    cout<<dp[n];
}
//Space Optimization Time Complexity: O(N)
//                   Space Complexity: O(1)
int f3(int n, vector<int> &dp)
{
    int prev2 = 0;
    int prev = 1;
  
    for(int i=2; i<=n; i++){
        int cur_i = prev2+ prev;
        prev2 = prev;
        prev= cur_i;
    }
    cout<<prev;
}

int main()
{   
    int n;
    cin>>n;
    vector<int>dp(n+1,-1); //step 0
    cout<<f(n,dp);
    return 0;
}