#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &books, int studs, int ans)
{
    int i = 0, n = books.size(), cnt = 0, cur = 0;
    while (i < n)
    {
        cur = 0;
        if (ans < books[i])
            return 0;
        while (cur + books[i] <= ans && i<n)
        {
            cur += books[i++];
        }
        ++cnt;
    }
    if (cnt <= studs)
        return 1;
    return 0;
}
int books(vector<int> &A, int B)
{
    if (A.size() < B)
        return -1;
    int l = 1e9, r = 0;
    for (auto i : A)
    {
        l = min(l, i);
        r += i;
    }
    int ans;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (isPossible(A, B, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
