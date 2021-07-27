double powxn(double x, int n)
{
    double ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans *= x;
            --n;
        }
        else
        {
            x *= x;
            n = n >> 1;
        }
    }
    return ans;
}

double NthRoot(int n, int k)
{
    double lo = 0;
    double hi = k;
    double eps = 1e-6;
    while (hi - lo > 1e-6)
    {
        double mid = (lo + hi) / 2;
        if (powxn(mid, n) < k)
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}