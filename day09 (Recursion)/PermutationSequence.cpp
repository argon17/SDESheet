#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<char> nums;
        for (int i = 1; i <= n; ++i)
        {
            nums.push_back('0' + i);
        }
        string ans;
        permute(nums, k - 1, ans);
        return ans;
    }

    void permute(vector<char> &nums, int k, string &ans)
    {
        if (nums.size() == 0)
            return;
        int ptSize = fact(nums.size() - 1);
        ans += nums[k / ptSize];
        nums.erase(nums.begin() + k / ptSize);
        permute(nums, k % ptSize, ans);
    }

    int fact(int n)
    {
        return n < 2 ? 1 : n * fact(n - 1);
    }
};