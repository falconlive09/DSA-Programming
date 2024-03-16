#include <bits/stdc++.h>
using namespace std;

//Binary Search T.C.-> O(n)+O(log m)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        if(matrix[i][0]<=target && target<=matrix[i][m-1]){
            int low=0,high=m-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(target==matrix[i][mid])    return true;
                else if(target>matrix[i][mid])   
                    low=mid+1;
                else    
                    high=mid-1;
            }
        }
        else
            continue;
    }   
    return false;
}

//Optimised
bool searchMatrix(vector<vector<int>>& matrix, int &target) {
    int n=matrix.size();
    int m=matrix[0].size();
    int low=0,high=(n*m-1);
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m,col=mid%m;
        if(target==matrix[row][col])    return true;
        else if(target>matrix[row][col])   low=mid+1;
        else        high=mid-1;
    }
    return false;
}