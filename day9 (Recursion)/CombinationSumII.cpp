#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> smallAns;
        genComb(candidates, target, ans, smallAns, 0);
        return ans;
    }
    
    void genComb(vector<int> candidates, int target, vector<vector<int>>& ans, vector<int>& smallAns, int ind){
        if(target==0){
            ans.push_back(smallAns);
            return; 
        }
        for(int i=ind; i<candidates.size(); ++i){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;
            smallAns.push_back(candidates[i]);
            genComb(candidates, target - candidates[i], ans, smallAns, i+1);
            smallAns.pop_back();
        }
    }
};