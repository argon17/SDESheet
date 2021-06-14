#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int sr = 0 - ( nums[i] );
            int lo = i + 1, hi = n - 1;
            while( lo < hi ){
                int s = nums[lo] + nums[hi];
                if( s < sr ){
                    lo++;
                    while( lo < hi && nums[lo] == nums[lo-1] ) lo++;
                } 
                else if( s > sr ){
                    hi--;
                    while( lo < hi && nums[hi] == nums[hi+1] ) hi--;
                } 
                else{
                    vector<int> _ans;
                    _ans.push_back(nums[i]);
                    _ans.push_back(nums[lo]);
                    _ans.push_back(nums[hi]);
                    ans.push_back(_ans);
                    lo++; hi--;
                    while( lo < hi && nums[lo] == nums[lo-1] ) lo++;
                    while( lo < hi && nums[hi] == nums[hi+1] ) hi--;
                }
            }
            while( i < n-1 && nums[i+1] == nums[i] ) i++;
        }
        return ans;
    }
};