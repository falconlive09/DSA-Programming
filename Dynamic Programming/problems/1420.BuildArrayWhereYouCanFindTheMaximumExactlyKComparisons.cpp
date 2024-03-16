#include <bits/stdc++.h>
using namespace std;

//Recursive
class Solution {
public:
    int mod=1e9+7;
    int f(int ind,int lenLIS,int prevLargest,int &n,int &m,int &k){
        if(ind==n){
            if(lenLIS==k)
                return 1;
            return 0;
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            if(i>prevLargest)
                ans+=f(ind+1,lenLIS+1,i,n,m,k);
            else
                ans+=f(ind+1,lenLIS,prevLargest,n,m,k);
        }
        return ans%mod;
    }
    int numOfArrays(int &n, int &m, int &k) {
        return f(0,0,0,n,m,k);
    }
};

//Memoization
int modu=1e9+7;
int f(int ind,int lenLIS,int prevLargest,
int &n,int &m,int &k,vector<vector<vector<int>>> &dp){
    if(ind==n){
        if(lenLIS==k)
            return 1;
        return 0;
    }
    if(dp[ind][lenLIS][prevLargest]!=-1)
        return dp[ind][lenLIS][prevLargest];
    int ans=0;
    for(int i=1;i<=m;i++){
        if(i>prevLargest)
            ans+=f(ind+1,lenLIS+1,i,n,m,k,dp);
        else
            ans+=f(ind+1,lenLIS,prevLargest,n,m,k,dp);
        ans=ans%modu;
    }
    return dp[ind][lenLIS][prevLargest]=ans;
}
int numOfArrays(int &n, int &m, int &k) {
    //ind 0-->n, lenLIS 0-->n, prevLargest 0-->m
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
    return f(0,0,0,n,m,k,dp);
}

//slight optimisation
int modu=1e9+7;
int f(int ind,int lenLIS,int prevLargest,
int &n,int &m,int &k,vector<vector<vector<int>>> &dp){
    if(ind==n){
        if(lenLIS==k)
            return 1;
        return 0;
    }
    if(lenLIS>k) //added condition if LIS exceeds k the resulting will give 0
            return 0; 
    if(dp[ind][lenLIS][prevLargest]!=-1)
        return dp[ind][lenLIS][prevLargest];
    int ans=0;
    for(int i=1;i<=m;i++){
        if(i>prevLargest)
            ans+=f(ind+1,lenLIS+1,i,n,m,k,dp);
        else
            ans+=f(ind+1,lenLIS,prevLargest,n,m,k,dp);
        ans=ans%modu;
    }
    return dp[ind][lenLIS][prevLargest]=ans;
}
int numOfArrays(int &n, int &m, int &k) {
    //ind 0-->n, lenLIS 0-->k, prevLargest 0-->m
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(m+1,-1)));
    return f(0,0,0,n,m,k,dp);
}

//DO TABULATION(not complete)
int numOfArrays(int &n, int &m, int &k) {
    int modu=1e9+7;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(m+1,0)));
    //Base Case
    for(int i=0;i<=m;i++)
        dp[n][k][i]=1;

    for(int ind=n-1;ind>=0;ind--){
        for(int lenLIS=k;lenLIS>=0;lenLIS--){
            for(int prevLargest=m;prevLargest>=0;prevLargest--){
                int ans=0;
                for(int i=1;i<=m;i++){
                    if(i>prevLargest)
                        ans+=dp[ind+1][lenLIS+1][i];
                    else
                        ans+=dp[ind+1][lenLIS][prevLargest];
                    ans=ans%modu;
                }
                dp[ind][lenLIS][prevLargest]=ans;
            }
        }
    }
    return dp[0][0][0];
}

int main(){
    Solution obj;
    int n=50,m=100,k=25;

    cout<<obj.numOfArrays(n,m,k);

    return 0;
}