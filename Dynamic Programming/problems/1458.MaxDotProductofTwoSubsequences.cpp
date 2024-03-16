#include <bits/stdc++.h>
using namespace std;

//Recursive
class Solution {
public:
    int f(int ind1,int ind2,vector<int>& nums1, vector<int>& nums2){
        if(ind1<0 || ind2<0)
            return -1e9; //if empty subsequence
        int dotProduct=0;
        int sp1,sp2,sp3;
        sp1=(nums1[ind1]*nums2[ind2])+f(ind1-1,ind2-1,nums1,nums2);
        sp2=f(ind1-1,ind2,nums1,nums2);
        sp3=f(ind1,ind2-1,nums1,nums2);
        // int sp4=f(ind1-1,ind2-1,nums1,nums2); coz we want non empty
        return dotProduct=max({sp1,sp2,sp3,nums1[ ind1]*nums2[ind2]});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        return f(n1-1,n2-1,nums1,nums2);
    }
};

//Memoization(shifting of index)
class Solution {
public:
    int f(int ind1,int ind2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
        if(ind1==0 || ind2==0)
            return -1e9;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        int sp1,sp2,sp3;
        sp1=nums1[ind1-1]*nums2[ind2-1]+f(ind1-1,ind2-1,nums1,nums2,dp);
        sp2=f(ind1-1,ind2,nums1,nums2,dp);
        sp3=f(ind1,ind2-1,nums1,nums2,dp);
        // int sp4=f(ind1-1,ind2-1,nums1,nums2,dp);
        return dp[ind1][ind2]=max({sp1,sp2,sp3,nums1[ind1-1]*nums2[ind2-1]});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return f(n1,n2,nums1,nums2,dp);
    }
};

//Tabulation
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1e9));
        
        for (int i=0;i<=n1;++i) {
            for (int j=0;j<=n2;++j) {
                if (i==0 || j==0) //Base Case
                    dp[i][j]=-1e9;
                else{
                    int dotProduct=nums1[i-1]*nums2[j-1]; 
                    dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+dotProduct,dotProduct});
                }
            }
        }
        return dp[n1][n2]; 
    }
};

//Space Optimisation
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> prev(n2+1,-1e9);
        vector<int> curr(n2+1,-1e9);
        
        for (int i=0;i<=n1;++i) {
            for (int j=0;j<=n2;++j) {
                if (i==0 || j==0) //Base Case
                    curr[j]=-1e9;
                else{
                    int dotProduct=nums1[i-1]*nums2[j-1]; 
                    curr[j]=max({prev[j],curr[j-1],prev[j-1]+dotProduct,dotProduct});
                }
            }
            prev=curr;
        }
        return prev[n2]; 
    }
};