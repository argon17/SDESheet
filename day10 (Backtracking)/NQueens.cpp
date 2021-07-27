#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // vector of all answers
        vector<vector<string>> ans;
        //single answer
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        solve(0, board, ans, n);
        return ans;
    }


    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n){
        // got one answer, push it
        if(col == n){
            ans.push_back(board);
            return;
        }
        // try to get any solution for each row
        for(int row = 0; row<n; row++){
            if( isSafe(row, col, board, n) ){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string> board, int n){
        int ro = row, cl = col;
        //check upeer diagonal
        while(ro>=0 && cl>=0){
            if(board[ro][cl] == 'Q') return false;
            ro--;
            cl--;
        }

        ro = row, cl = col;
        //check left side of the row
        while(cl>=0){
            if(board[ro][cl] == 'Q') return false;
            cl--;
        }

        ro = row, cl = col;
        //check lower diagonal
        while(ro<n && cl>=0){
            if(board[ro][cl] == 'Q') return false;
            ro++;
            cl--;
        }
        return true;
    }
};