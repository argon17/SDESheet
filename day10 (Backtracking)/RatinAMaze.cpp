#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void letsGoFrom(int r, int c, vector<vector<int>> &m, vector<string> &ans, vector<vector<bool>> &vis, string cur, int n, int dirs[8], string moves)
    {
        if (r == n - 1 && c == n - 1)
        {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dirs[i * 2];
            int nc = c + dirs[i * 2 + 1];
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc] && m[nr][nc] == 1)
            {
                vis[r][c] = 1;
                letsGoFrom(nr, nc, m, ans, vis, cur + moves[i], n, dirs, moves);
                vis[r][c] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        int dirs[8] = {1, 0, 0, -1, 0, 1, -1, 0};
        string moves = "DLRU";
        if (m[0][0])
            letsGoFrom(0, 0, m, ans, vis, "", n, dirs, moves);
        return ans;
    }
};
