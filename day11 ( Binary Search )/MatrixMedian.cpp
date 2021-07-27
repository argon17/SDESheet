#include <bits/stdc++.h>
using namespace std;

int cntLess(vector<vector<int>> &mat, int rows, int cols, int n)
{
    int cnt = 0;
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (mat[r][c] < n) ++cnt;
            else break;
        }
    }
    return cnt;
}

int findMedian(vector<vector<int>> &A)
{
    int rows = A.size(), cols = A[0].size();
    int l = 0, r = 1e9;
    int ans;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (cntLess(A, rows, cols, mid) <= (rows * cols) >> 1)
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
