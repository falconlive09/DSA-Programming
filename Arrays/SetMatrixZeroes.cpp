#include <bits/stdc++.h>
using namespace std;

//optimal
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        //int col[m]; -> matrix[0][..]   
        //int row[n]; -> matrix[..][0]
        int col0=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]==0) {
                    //marking the ith row
                    //marking the jth col
                    matrix[i][0]=0;
                    if(j!=0)
                        matrix[0][j]=0;
                    else    
                        col0=0;
                }
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[i][j]!=0) {
                    //check for col & row
                    if(matrix[0][j]==0 || matrix[i][0]==0)  matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0) {
            for(int j=0;j<m;j++) {
                matrix[0][j]=0;
            }
        }
        if(col0==0) {
            for(int i=0;i<n;i++) {
                matrix[i][0]=0;
            }
        }
    }
};

//better
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int col[m],row[n];
        memset(col,0,sizeof(col));
        memset(row,0,sizeof(row));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]==0) {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(row[i] || col[j]) 
                    matrix[i][j]=0;
            }
        }
    }
};