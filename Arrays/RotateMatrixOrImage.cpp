#include <bits/stdc++.h>
using namespace std;

//optimal T.C.-> O(n/2 * n/2)+O(n * n/2) S.C.-> O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //nxn matrix
        int n=matrix.size();
        //transpose the matrix
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse the rows
        for(int i=0;i<n;i++) {
            //O(N/2) or use 2 pointer approach
            reverse(matrix[i].begin(),matrix[i].end());
        }
     }
};