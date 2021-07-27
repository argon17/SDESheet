#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
    int mergeSort(vector<int> &nums, int lo, int hi){
        if(lo>=hi) return 0;
        int mid = (lo+hi)>>1;
        int count = 0;
        count += mergeSort(nums, lo, mid);
        count += mergeSort(nums, mid+1, hi);
        count += merge(nums, lo, mid, hi);
        return count;
    }
    int merge(vector<int> &nums, int lo, int mid, int hi){
        int count = 0;
        int j = mid + 1;
        for(int i=lo; i<=mid; ++i){
            while(j <= hi && nums[i] > 2LL*nums[j]){
                ++j;
            }
            count += (j - mid - 1);
        }
        vector<int> temp;
        int l = lo, r = mid+1;
        // keep comparing & pushing
        while(l <= mid && r <= hi){
            if(nums[l] < nums[r]) temp.push_back(nums[l++]);
            else temp.push_back(nums[r++]);
        }
        // left elements in left
        while(l<=mid) temp.push_back(nums[l++]);
        // left elements in right
        while(r<=hi) temp.push_back(nums[r++]);
        // merge
        for(int i=lo; i<=hi; ++i) nums[i] = temp[i-lo];
        return count;
    }
};