#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

// O(N^3)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int target_rem = target - nums[i] - nums[j];
                int l = j+1, r = n-1;
                while(l<r){
                    int two_sum = nums[l]+nums[r];
                    //less sum, need to inc l
                    if(two_sum < target_rem){
                        ++l;
                        //skip if processed nums[l] again appeared
                        while(l<r && nums[l]==nums[l-1]) ++l;
                    } 
                    //large sum, need to dec r
                    else if(two_sum > target_rem){
                        --r;
                        //skip if processed nums[r] again appeared
                        while(l<r && nums[r]==nums[r+1]) --r;
                    }
                    // got the combinn, push it
                    else{
                        vector<int> _ans;
                        _ans.push_back(nums[i]);
                        _ans.push_back(nums[j]);
                        _ans.push_back(nums[l]);
                        _ans.push_back(nums[r]);
                        ans.push_back(_ans);
                        ++l; --r;
                        //skip if processed nums[l] again appeared
                        while(l<r && nums[l]==nums[l-1]) ++l;
                        //skip if processed nums[r] again appeared
                        while(l<r && nums[r]==nums[r+1]) --r;
                    }
                }
                //skip if processed nums[j] again appears
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            //skip if processed nums[i] again appears
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};

int main() {
    int n, target, tmp; cin>>n>>target;
    vector<int> v;
    rep(i,n){
        cin>>tmp;
        v.push_back(tmp);
    }
    Solution nub;
    vector<vector<int>> ans = nub.fourSum(v, target);
    for(auto it1: ans){
        for(auto it2: it1) cout<<it2<<" ";
        cout<<"\n";
    }
	return 0;
}