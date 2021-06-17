#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// Naive O(NlogN)
/*
void solve()
{
    ll n; cin>>n;
    vi ar(n);
    rep(i, 0, n){
        cin>>ar[i];
    }
    sort(all(ar));
    ll cur = 1, mx = 0;
    rep(i, 1, n){
        if(ar[i] == ar[i-1]+1) ++cur, mx = max(cur, mx);
        else  cur = 1;
    }
    cout<<mx;
}
*/
// O(N) approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int n : nums) st.insert(n);
        int mx = 0;
        for(int n : st){
            if(st.count(n-1)^1){
                int cur = 0;
                while(st.count(n++)){
                    ++cur;
                    mx = max(cur, mx);
                }
            }
        }
        return mx;
    }
};