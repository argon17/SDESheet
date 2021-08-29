#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            if(nums[i] > 0) break;
            if (i && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] == target)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    ++l; --r;
                }
                else if (nums[l] + nums[r] < target) ++l;
                else --r;
            }
        }
        return ans;
    }
};