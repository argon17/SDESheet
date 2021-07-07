#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        sort(arr, arr + n);
        sort(dep, dep + n);

        int mx = 0, i = 1, j = 0, cur = 1;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
                ++cur, ++i;
            else
                --cur, ++j;
            mx = max(cur, mx);
        }
        return mx;
    }
};