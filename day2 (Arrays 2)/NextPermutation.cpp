#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;
    // find rtl non decreasing pivot
    for(int i=n-1; i>0; --i){
        if(nums[i]>nums[i-1]){
            pivot = i-1;
            break;
        }
    }
    if(pivot==-1){
        reverse(nums.begin()+pivot+1, nums.end());
        return;
    }
    // find just greater elem from rtl than nums[pivot] and swap
    for(int i=n-1; i>pivot; --i){
        if(nums[i]>nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }
    // reverse after pivot
    reverse(nums.begin()+pivot+1, nums.end());
}