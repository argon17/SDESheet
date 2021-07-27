#include <bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if (n > m) return kthElement(arr2, arr1, m, n, k);
    int l = max(0, k-m), r = min(k, n);
    while (l <= r) {
        int f = (l + r) >> 1;
        int s = k - f;
        // cerr << l << " " << f << " " << s << " " << r << endl;
        // Edge Cases
        int l1 = f == 0 ? -1e9 : arr1[f - 1];
        int l2 = s == 0 ? -1e9 : arr2[s - 1];
        int r1 = f == n ? 1e9 : arr1[f];
        int r2 = s == m ? 1e9 : arr2[s];
        if (l1 <= r2 && l2 <= r1) return max(l1, l2);
        else if (l1 > r2) r = f - 1;
        else l = f + 1;
    }
    return -1;
}