#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0, maxx = INT_MIN;
        
        // iterate over the array
        for(auto it : nums ){
            // add the element to the previous sum
            sum += it;
            // assign maxx to max of sum and maxx
            maxx = max( sum, maxx );
            // if sum is negative, don't carry it further
            sum = sum < 0 ? 0 : sum;
        }
        return maxx;
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