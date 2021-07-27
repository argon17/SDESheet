#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == '1')
                {
                    ++ans;
                    dfs(grid, r, c);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        grid[r][c] = '0';
        int dir[5] = {0, 1, 0, -1, 0};
        for (int i = 0; i < 4; ++i)
        {
            int newR = r + dir[i], newC = c + dir[i + 1];
            if (isValid(grid, newR, newC))
                dfs(grid, newR, newC);
        }
    }

    bool isValid(vector<vector<char>> &grid, int r, int c)
    {
        int rows = grid.size(), cols = grid[0].size();
        return (r < rows && r >= 0 && c < cols && c >= 0 && grid[r][c] == '1');
    }
};