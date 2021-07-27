#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// For Longest Palindromic Subsequence, find LCS of the string and reversed string

// Recursion and Memoization, Top Down Approach
class Solution
{
public:
    int longestCommonSubsequence(string &text1, string &text2, int m, int n, int memo[][1001])
    {
        if (m == 0 || n == 0)
        {
            return 0;
        }
        if (memo[m][n] != -1)
        {
            return memo[m][n];
        }
        if (text1[m - 1] == text2[n - 1])
        {
            return memo[m][n] = 1 + longestCommonSubsequence(text1, text2, m - 1, n - 1, memo);
        }
        else
        {
            return memo[m][n] = max(longestCommonSubsequence(text1, text2, m - 1, n, memo), longestCommonSubsequence(text1, text2, m, n - 1, memo));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        int memo[1001][1001];
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                memo[i][j] = -1;
            }
        }
        return longestCommonSubsequence(text1, text2, m, n, memo);
    }
};

// Tabulation Method, Bottom Up Approach
// dp[i][j] = lcs of s1 of i length and s2 of j length

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int r = 1; r <= m; ++r)
        {
            for (int c = 1; c <= n; ++c)
            {
                if (text1[r - 1] == text2[c - 1])
                {
                    dp[r][c] = 1 + dp[r - 1][c - 1];
                }
                else
                {
                    dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

// Printing LCS
void argon17()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.length(), n = s2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans = s1[i - 1] + ans;
            --i, --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    cout << ans;
}
