#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        gen(0, target, candidates, ds, ans);
        return ans;
    }
private:
    void gen(int ind, int target, vector<int> nums, vector<int>& ds, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<nums.size(); ++i){
            if(i>ind && nums[i]==nums[i-1]) continue;
            // try on each next elements
            if(target<nums[i]) return;
            ds.push_back(nums[i]);
            gen(i+1, target-nums[i], nums, ds, ans);
            ds.pop_back();
        }
    }
};