#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // idea is to find if subset sum of totalsum/2 exists...
    // classic 0/1 knapsack category

    // dp[i][j] = is it posibble to make sum j using first i elements
    bool canPartition(vector<int>& nums) {

        int n = nums.size(), target = 0;

        for(int num : nums) target += num;
        if(target&1) return false;
        target >>= 1;

        vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));
        
        // 0 sum is always possible
        for(int i=0; i<=n; ++i) dp[i][0] = 1;

        // 0 elements can't make any sum grater than 0
        for(int i=1; i<=target; ++i) dp[0][i] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                // either you don't include current element
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    // or you include current element
                    // current element can only be included,
                    // if required sum is greater than current element
                    dp[i][j]  = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        
        return dp[n][target];
    }
};