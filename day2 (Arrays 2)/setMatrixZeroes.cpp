#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size(), c = matrix[0].size();
    vector<bool> rowb(r, 0), colb(c, 0);
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(matrix[i][j]==0) rowb[i] = 1, colb[j] = 1;
        }
    }
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(rowb[i] || colb[j]) matrix[i][j] = 0;
        }
    }
}