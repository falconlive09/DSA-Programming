#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1000000007;

int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    //Base case 1:
    if (i > j) return 0;
    //Base case 2:
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp, dp);
        ll lF = f(i, ind - 1, 0, exp, dp);
        ll rT = f(ind + 1, j, 1, exp, dp);
        ll rF = f(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, 1, exp, dp);
}


//Tabulation
#define ll long long 
int mod = 1000000007;
int evaluateExp(string & exp) {
    int n= exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, 0)));  
    for(int i=0; i<n; i++){
        dp[i][i][1] = exp[i] == 'T';
        dp[i][i][0] = exp[i] == 'F';
    }
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            for(int isTrue=0; isTrue <=1; isTrue++){
                ll ways=0;
                for(int ind =i+1; ind <= j-1; ind=ind+2){
                    ll lT = dp[i][ind-1][1];
                    ll lF = dp[i][ind-1][0];
                    ll rT = dp[ind+1][j][1];
                    ll rF = dp[ind+1][j][0];
                    if(exp[ind] == '&'){
                        if(isTrue) ways = (ways + (lT * rT)%mod)%mod;
                        else ways = (ways + (lT*rF)%mod + (lF*rF)%mod + (lF*rT)%mod)%mod;
                    }
                    else if(exp[ind] == '|'){
                        if(isTrue) 
                            ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else 
                            ways = (ways + (lF*rF)%mod)%mod;
                    }
                    else{
                        if(isTrue) 
                            ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else    
                            ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n-1][1];
}
