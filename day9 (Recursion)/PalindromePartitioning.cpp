#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> smallAns;
        gen(0, s, smallAns, ans);
        return ans;
    }

    void gen(int ind, string s, vector<string> &smallAns, vector<vector<string>> &ans)
    {
        if (ind == s.length())
        {
            ans.push_back(smallAns);
            return;
        }
        for (int i = ind; i < s.length(); ++i)
        {
            if (isPalindrome(s, ind, i))
            {
                smallAns.push_back(s.substr(ind, i - ind + 1));
                gen(i + 1, s, smallAns, ans);
                smallAns.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
                return 0;
        }
        return 1;
    }
};