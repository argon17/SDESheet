#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            // partner found :), push to ans vector
            if( mpp.find( target-nums[i] ) != mpp.end()){
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
            }
            // noone is there for you, wait in the map :(
            mpp[nums[i]] = i;
        }
        return ans;
    }
};

int main() {
    int n, target, tmp; cin>>n>>target;
    vector<int> v, ans;
    rep(i,n){
        cin>>tmp;
        v.push_back(tmp);
    }
    Solution nub;
    ans = nub.twoSum(v, target);
    for(auto it: ans) cout<<it<<" ";
	return 0;
}