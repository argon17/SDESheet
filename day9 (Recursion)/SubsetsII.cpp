#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> smallAns;
        genSubsets(nums, ans, smallAns, 0);
        return ans;
    }
private:
    void genSubsets(vector<int>& nums, vector<vector<int>> &ans, vector<int> &smallAns, int ind){
        ans.push_back(smallAns);
        for(int i=ind; i<nums.size(); ++i){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            smallAns.push_back(nums[i]);
            genSubsets(nums, ans, smallAns, i+1);
            smallAns.pop_back();
        }
    }
};