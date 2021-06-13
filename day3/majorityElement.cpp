#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, e = 0;
        for(int num : nums){
            if(e == num) ++cnt;
            else if(cnt == 0) e = num;
            else --cnt;
        }
        return e;
    }
};