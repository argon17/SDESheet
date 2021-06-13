class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long np = n;
        if(n<0) np = -1*np;
        while(np){
            if(np&1){
                ans *= x;
                np--;
            }else{
                x *= x;
                np = np>>1;
            }
        }
       return n>0 ? ans : 1/ans;
    }
};