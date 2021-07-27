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

// all subsets, O(2^n) TC
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> smallAns;
        gen(nums, ans, smallAns, 0);
        return ans;
    }
    private:
    void gen(vector<int> nums, vector<vector<int>> &ans, vector<int> &smallAns, int ind){
        if(ind==nums.size()){
            ans.push_back(smallAns);
            return;
        }
        // not pick
        gen(nums, ans, smallAns, ind+1);
        smallAns.push_back(nums[ind]);
        gen(nums, ans, smallAns, ind+1);
        // pick
        smallAns.pop_back();
    }
};