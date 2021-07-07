#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        genPermutation(0, nums, ans);
        return ans;
    }
    private:
    void genPermutation(int index, vector<int>& nums, vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); ++i){
            swap(nums[index], nums[i]);
            genPermutation(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
};

// another approach, not backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        for (int i = 0, n = factorial(nums.size()); i < n; i++) {
            perms.push_back(nums);
            nextPermutation(nums);
        }
        return perms;
    }
private:
    int factorial(int n) {
        int f = 1;
        while (n > 1) {
            f *= n--;
        }
        return f;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};