#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe1(int row,int col, vector<string> &board,int &n)
    {   //not optimised well 3*O(n) created
        //check upper diagonal
        int duprow=row;
        int dupcol=col;

        while(row>=0 && col>=0) //O(n)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0) //O(n)
        {
            if(board[row][col]=='Q')
                return false;
            col--; 
        }
        row=duprow;
        col=dupcol;
        while(row<n && col>=0) //O(n)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe1(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.'; //backtrack remove for next row to check
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.'); //if n=4, s will contain [. . . .]
        for (int i = 0 ;i < n;i++) //creation of empty chessboard of size nxn
        {
            board[i]=s; 
        }

        solve(0,board,ans,n);
        return ans;
    }
};