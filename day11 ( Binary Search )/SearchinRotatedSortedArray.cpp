#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            // check if exists in sorted side
            // if left half is sorted
            else if (nums[mid] > nums[r])
            {
                // if exists in left half
                if (target < nums[mid] && target >= nums[l]) r = mid - 1;
                else l = mid + 1;
            }
            // if right half is sorted
            else
            {
                // if exists in right half
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};