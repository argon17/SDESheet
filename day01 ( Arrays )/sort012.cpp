#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // before lo all are 0's
        // after hi all are 2's
        int lo = 0, hi = n-1;
        for(int i=0; i<=hi; ++i){
            if(nums[i]==2) swap(nums[i--], nums[hi--]);
            else if(nums[i]==0) swap(nums[i], nums[lo++]);
        }
    }
};

int main() {
    int n, tmp; cin>>n;
    vector<int> v;
    rep(i,n){
        cin>>tmp;
        v.push_back(tmp);
    }
    Solution nub;
    nub.sortColors(v);
    rep(i,n) cout<<v[i]<<" ";
	return 0;
}