//not working
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int i, int j, vector<vector<char>>& matrix) {
        if (i == 0 && j == 0) 
        { 
            if(matrix[i][j] == '1')
                return 1;  
            else
                return 0;
        }
        if (i < 0 || j < 0)
            return 0;
        int up = f(i - 1, j, matrix);
        int left = f(i, j - 1, matrix);
        int diag = f(i - 1, j - 1, matrix);
        if (matrix[i][j] == '1') {
            return max(max(up, left), diag) + 1;
        }
        return 0;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        return f(matrix.size() - 1, matrix[0].size() - 1, matrix);
    }
};