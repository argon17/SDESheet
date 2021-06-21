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
        // push every elements in a set
        set<int> elements;
        for(int n : nums) elements.insert(n);
        int mx = 0;
        // iterate and find the min of a seq, 
        // for that just check if num-1 exists in the set or not
        // if exists, it is not the minimum
        for(int n : elements){
            // found the minimum, now find length of this subsequence
            if(elements.count(n-1)^1){
                int cur = 0;
                while(elements.count(n++)){
                    ++cur;
                    mx = max(cur, mx);
                }
            }
        }
        return mx;
    }
};