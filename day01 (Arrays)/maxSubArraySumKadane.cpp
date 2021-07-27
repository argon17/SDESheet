#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int cur = 0, mx = INT_MIN;
        
        // iterate over the array
        for(auto it : nums ){
            // add the element to the previous cur
            cur += it;
            // assign maxx to max of cur and maxx
            mx = max( cur, mx );
            // if cur is negative, don't carry it further
            cur = cur < 0 ? 0 : cur;
        }
        return mx;
    }
};

int main() {
    int n, x;
    cin>>n;
    vector<int> v;
    while(n--){
        cin>>x;
        v.push_back(x);
    }
    Solution nub;
    int ans = nub.maxSubArray(v);
    cout<<ans;
	return 0;
}