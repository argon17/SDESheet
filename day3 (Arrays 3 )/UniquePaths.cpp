#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = m - 1;
        return ncr(N, r);
    }
    int ncr(int n, int r) {
        double ans = 1;
        for (int i = 1; i <= r; ++i) {
            ans = ans * (n - r + i) / i;
        }
        return (int)ans;
    }
};