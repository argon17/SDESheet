#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to merge the arrays.
    void merge(long long a[], long long b[], int n, int m)
    {
        // code here
        int gap = (n + m + 1) / 2;
        while (gap) {
            int i = 0, j = gap;
            while (j < (n + m)) {
                if (i < n && j < n) {
                    if (a[i] > a[j]) swap(a[i], a[j]);
                }
                else if (i < n && j >= n) {
                    if (a[i] > b[j - n]) swap(a[i], b[j - n]);
                }
                else{
                    if (b[i - n] > b[j - n]) swap(b[i - n], b[j - n]);
                }
                ++i; ++j;
            }
            gap = gap < 2 ? 0 : (gap + 1) / 2;
        }
    }
};
