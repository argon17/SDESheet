#include <bits/stdc++.h>
using namespace std;

// O(N^3) - two pointer approach

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
        {
            // skip if processed nums[i] again appeared
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; ++j)
            {
                // skip if processed nums[j] again appeared
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int targetLeft = target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while (l < r)
                {
                    if (nums[l] + nums[r] == targetLeft)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        // skip if processed nums[l] again appeared
                        do{ ++l; } while (l < r && nums[l] == nums[l - 1]);
                        // skip if processed nums[r] again appeared
                        do{ --r; } while (l < r && nums[r] == nums[r + 1]);
                    }
                    else if (nums[l] + nums[r] < targetLeft) ++l;
                    else --r;
                }
            }
        }
        return ans;
    }
};