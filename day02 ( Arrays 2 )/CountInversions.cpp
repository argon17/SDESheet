#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return count(arr, 0, N - 1);
    }

    long long count(long long arr[], long long lo, long long hi)
    {
        if (lo == hi)
            return 0;
        long long ans = 0;
        long long mid = (lo + hi) >> 1;
        ans += count(arr, lo, mid);
        ans += count(arr, mid + 1, hi);
        ans += merge(arr, lo, mid, hi);
        return ans;
    }

    long long merge(long long arr[], long long lo, long long mid, long long hi)
    {

        long long ans = 0;
        int i = lo, j = mid + 1;
        for (int i = lo; i <= mid; ++i)
        {
            while (j <= hi && arr[i] > arr[j])
                ++j;
            ans += j - mid - 1;
        }
        int gap = (hi - lo + 1 + 1) / 2;
        while (gap)
        {
            int l = lo, r = l + gap;
            while (r <= hi) {
                if (arr[l] > arr[r]) swap(arr[l], arr[r]);
                ++l; ++r;
            }
            gap = gap < 2 ? 0 : (gap + 1) / 2;
        }
        return ans;
    }
};
