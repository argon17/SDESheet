#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> smallAns;
        genComb(candidates, target, smallAns, ans, 0);
        return ans;
    }
private:
    void genComb(vector<int> candidates, int target, vector<int> &smallAns, vector<vector<int>> &ans, int ind){
        if(ind==candidates.size()){
            if(target==0) ans.push_back(smallAns);
            return;
        }
        // don't pick
        genComb(candidates, target, smallAns, ans, ind+1);
        // pick, if less than or equal to target
        if(target>=candidates[ind]){
            smallAns.push_back(candidates[ind]);
            genComb(candidates, target-candidates[ind], smallAns, ans, ind);
            smallAns.pop_back();
        }
    }
};