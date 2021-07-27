class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int ans = 0;
        while(n){
            ++ans;
            n -= n&-n;
        }
        return ans;
    }
};