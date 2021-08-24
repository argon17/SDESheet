class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int ans = 0;
        for(int r=0; r<rows; ++r)
            for(int c=0; c<cols; ++c)
                ans = max(ans, dfs(r, c, matrix, dp));
        return ans;
    }
private:
    int dfs(int r, int c, vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(dp[r][c]) return dp[r][c];
        int dirs[] = {-1, 0, 1, 0, -1};
        int rows = mat.size();
        int cols = mat[0].size();
        for(int i=0; i<4; ++i){
            int nr = r+dirs[i], nc = c+dirs[i+1];
            if(inside(nr, nc, rows, cols) && mat[nr][nc]>mat[r][c])
                dp[r][c] = max(dp[r][c], dfs(nr, nc, mat, dp));
        }
        return ++dp[r][c];
    }
    bool inside(int i, int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
};
