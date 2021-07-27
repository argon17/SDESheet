#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m  = word1.length(), n = word2.length();
        // dp[x][y] = min edit cost from word1 of x length to word2 of y length
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<=m; ++i){
            // all deletions
            dp[i][0] = i;
        }
        for(int j=0; j<=n; ++j){
            // all insertions
            dp[0][j] = j;
        }

        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(word1[i-1]==word2[j-1]){
                    // no need to do anything
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    // insert, delete and replace respectively
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};