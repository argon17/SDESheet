#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            // check if exists in sorted side
            // if left half is sorted
            else if (nums[mid] >= nums[l])
            {
                // if exists in left half
                if (nums[l] <= target && target <= nums[mid]) r = mid;
                else l = mid + 1;
            }
            // if right half is sorted
            else
            {
                // if exists in right half
                if (nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid;
            }
        }
        if(nums[l] == target) return l;
        return -1;
    }
};

/* Some insights of this format of binary search
    left half =  [lo ... mid]
    right half = [(mid+1) ... hi]
    ignore left half => lo = mid + 1
    ignore right half => hi = mid
*/