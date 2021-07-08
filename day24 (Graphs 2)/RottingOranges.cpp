#include<bits/stdc++.h>
using namespace std;

// Multi source BFS approach
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        // counting all fresh oranges and push all rotten ones to the queue
        for(int r=0; r<rows; ++r){
            for(int c=0; c<cols; ++c){
                if(grid[r][c]==2) q.push({r, c});
                if(grid[r][c]==1) ++fresh;
            }
        }
        // (0,1) (0,-1) (-1,0) (1,0)
        int dir[5] = {0, 1, 0, -1, 0};
        int ans = 0;
        // loop for levels, each level gets affected after one minute
        while(q.size() && fresh){
            int sz = q.size();
            // start multi source bfs
            while(sz--){
                // take out the first rotten orange
                pair<int, int> p = q.front();
                q.pop();
                for(int i=0; i<4; ++i){
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];
                    if(r>=0 && r<rows && c>=0 && c<cols && grid[r][c]==1){
                        // if valid position, then it is rotten, push to queue for later level
                        grid[r][c] = 2;
                        q.push({r, c});
                        --fresh;
                    }
                }
            }
            ++ans;
        }
        return fresh ? -1 : ans;
    }
};