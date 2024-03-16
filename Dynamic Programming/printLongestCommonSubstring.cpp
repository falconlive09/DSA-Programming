#include<bits/stdc++.h>
using namespace std;

string findLCS(int n, int m,string &s, string &t){
    //O(nxm)
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int j=0;j<=m;j++)
		dp[0][j]=0;
	for(int i=0;i<=n;i++)
		dp[i][0]=0;
    int maxLen=0,maxi=0,maxj=0; //for extracting maximum length of common substring & its location
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
                if(dp[i][j]>maxLen){
                    maxLen=dp[i][j]; 
                    maxi=i;
                    maxj=j;
                }   
            }
			else
				dp[i][j]=0;
		}
	}
    //length of lcs is in dp[n][m]
    string ans;
    //O(n+m)
    int i=maxi, j=maxj;
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1])
        {
            ans=s[i-1]+ans;
            --i;
            --j;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            --i;
        else
            --j;
    }
    return ans;
}