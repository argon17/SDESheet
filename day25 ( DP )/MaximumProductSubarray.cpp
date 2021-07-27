#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int mx[n], mn[n];
        mx[0] = nums[0], mn[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            mx[i] = max({nums[i], nums[i] * mx[i - 1], nums[i] * mn[i - 1]});
            mn[i] = min({nums[i], nums[i] * mx[i - 1], nums[i] * mn[i - 1]});
        }
        int ans = INT_MIN;
        for (int n : mx)
        {
            ans = max(n, ans);
        }
        return ans;
    }
};