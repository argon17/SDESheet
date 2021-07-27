#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);
    
    for(int i=2*n-1; i>=0; --i){
        
        while(st.size() && nums[i%n] >= st.top()) st.pop();
        if(i<n){
            if(st.empty()) ans[i] = -1;
            else ans[i%n] = st.top();
        }
        st.push(nums[i%n]);
        
    }
    return ans;
}