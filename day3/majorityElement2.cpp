#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // there can only be two majority elements
        int c1 = 0, c2 = 0, e1 = 0, e2 = 0;
        for(auto num : nums){
            if(num == e1) ++c1;
            else if(num == e2) ++c2;
            else if(c1 == 0) e1 = num, c1 = 1;
            else if(c2 == 0) e2 = num, c2 = 1;
            else --c1, --c2;
        }
        int cnt1 = 0, cnt2 = 0;
        for(auto num : nums){
            if(num == e1) ++cnt1;
            else if(num == e2) ++cnt2;
        }
        vector<int> ans;
        if(cnt1>nums.size()/3) ans.push_back(e1);
        if(cnt2>nums.size()/3) ans.push_back(e2);
        return ans;
    }
};