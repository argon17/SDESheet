#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi)
        {
            int mid = (lo + hi) >> 1;
            // if right half sorted
            if(nums[mid] <= nums[hi]) {
                // if exists in right half
                if(nums[mid] < target && target <= nums[hi]) lo = mid + 1;
                else hi = mid;
            }
            // left half sorted
            else{
                // if exists in left half
                if(nums[lo] <= target && target <= nums[mid]) hi = mid;
                else lo = mid + 1;
            }
        }
        if(nums[lo] == target) return lo;
        return -1;
    }
};