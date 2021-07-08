#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while(lo<hi){
            int mid = (lo+hi)>>1;
            if(nums[mid]==nums[mid^1]) lo = mid+1;
            else hi = mid;
        }
        return nums[lo];
    }
};