#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, e = 0;
        for(int num : nums){
            if(cnt == 0) e = num;
            if(e == num) ++cnt;
            else --cnt;
        }
        return e;
    }
};