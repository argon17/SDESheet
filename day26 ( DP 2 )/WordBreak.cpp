#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> exists;
        for (auto it : wordDict)
        {
            exists[it] = 1;
        }
        int n = s.length();
        vector<bool> dp(n + 1);
        // empty string is always possible
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                // if till j is breakable and from j to i is present in dict,
                // yess, we can break the string till i
                if (dp[j] && exists[s.substr(j, i - j)])
                {
                    dp[i] = 1;
                    // got the answer for this index, now move on
                    break;
                }
            }
        }
        return dp[n];
    }
};