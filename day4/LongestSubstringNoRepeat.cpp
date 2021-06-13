#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int l = 0, r = 0, n = s.length(), ans = 0;
        while(r<n){
            if( m.find(s[r]) != m.end() ) 
                // why max ? if m[s[r]] < l, we don't care
                // it's not in our substring range l -> r
                // it was stored due to one of previous substrings
                l = max(m[s[r]] + 1, l);
            m[s[r]] = r;
            ans = max(ans, r++-l+1);
        }
        return ans;
    }
};