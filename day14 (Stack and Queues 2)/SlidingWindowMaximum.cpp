#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<nums.size(); ++i){
            // always keep max at front and then elements in decreasing order
            while(dq.size() && nums[dq.back()]<nums[i]) dq.pop_back();
            // keep popping, if outside elements are at the front of the deque
            while(dq.size() && dq.front()<=i-k) dq.pop_front();
            // push the current element
            dq.push_back(i);
            // add front element of the deque to answer
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};