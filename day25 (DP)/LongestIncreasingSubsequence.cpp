#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    // dp[x] = LIS till x
    vector<int> dp(n, 1);
    int ans = 1;
    for(int i=1; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(nums[j]<nums[i]){
                dp[i] = max(dp[i], 1+dp[j]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}