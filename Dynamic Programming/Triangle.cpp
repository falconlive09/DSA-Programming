#include <bits/stdc++.h> 
using namespace std;
//Memoization
int f(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>>& dp){
	if(i == (n-1)){
		return triangle[i][j];
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	return dp[i][j] = triangle[i][j] + min(f(triangle, i+1, j, n, dp), f(triangle, i+1, j+1, n, dp));
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return f(triangle, 0, 0, n, dp);
}

//Tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));
	for(int j=0;j<n;j++){
		dp[n-1][j]=triangle[n-1][j];
	}
	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			//int down=triangle[i][j]+dp[i+1][j];
			//int diagonal=triangle[i][j]+dp[i+1][j+1];
			dp[i][j]=min(triangle[i][j]+dp[i+1][j], triangle[i][j]+dp[i+1][j+1]);
		}
	}
	return dp[0][0];
}
//Space Optimization
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> front(n,0);
	for(int j=0;j<n;j++){
		front[j]=triangle[n-1][j];
	}
	for(int i=n-2;i>=0;i--){
		vector<int>cur(n,0);
		for(int j=i;j>=0;j--){
			//int down=triangle[i][j]+dp[i+1][j];
			//int diagonal=triangle[i][j]+dp[i+1][j+1];
			cur[j]=min(triangle[i][j]+front[j], triangle[i][j]+front[j+1]);
		}
		front=cur;
	}
	return front[0];
}