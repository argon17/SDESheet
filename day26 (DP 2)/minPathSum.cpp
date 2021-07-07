#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int y = grid.size(), x = grid[0].size();
        // dp[y][x] = minPathSum to reach (x, y)
        int dp[y][x];
        dp[0][0] = grid[0][0];
        for(int i=1; i<x; i++){
            dp[0][i] = grid[0][i]+dp[0][i-1];
        }
        for(int i=1; i<y; i++){
            dp[i][0] = grid[i][0]+dp[i-1][0];
        }
        for(int i=1; i<y; i++){
            for(int j=1; j<x; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[y-1][x-1];
    }
};

// space optimized dp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> dp(cols, grid[0][0]);
        for(int c=1; c<cols; ++c) dp[c] = dp[c-1]+grid[0][c];
        for(int r=1; r<rows; ++r){
            dp[0] += grid[r][0];
            for(int c=1; c<cols; ++c){
                dp[c] = grid[r][c] + min(dp[c], dp[c-1]);
            }
        }
        return dp[cols-1];
    }
};