#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int& k) {
        int ans = 0, xr = 0;
        unordered_map<int,int> freq;
        for(int n : nums){
            xr ^= n;
            if(xr == k) ++ans;
            // for sum k => freq.find(sum-k)
            if(freq.find(xr ^ k) != freq.end()) ans += freq[xr^k];
            ++freq[xr];
        }
        return ans;
    }
};

int main(){
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    Solution nub; 
    cout<<nub.solve(v, k);
    return 0;
}