#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // if exactly one of the operands is negative
        // result will be negative
        bool isNeg = (dividend < 0) ^ (divisor < 0);
        // now we've to calculate a/b
        long a = abs(dividend), b = abs(divisor);
        // start with all bits of ans as 0
        long ans = 0;
        for(int i=31; i>=0; --i){
            // if b*2^i is less than or equal to a
            // set the i'th bit of ans
            // decrease a by b*2^i
            if(b<<i <= a){
                ans |= 1LL<<i;
                a -= b<<i;
            }
        }
        // if negative, ans will be negative
        if(isNeg) ans = -ans;
        // check for overflow
        if(ans>=INT_MAX) return INT_MAX;
        return ans;
    }
};