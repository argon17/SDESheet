#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0, mx = 0;
        for(int i=0; i<nums.size(); i++){
            if( nums[i] == 1 ){
                ++cur;
                mx = max(cur, mx);
            }else cur = 0;
        }
        return mx;
    }
    // shorter code :)
    int findMaxConsecutiveOnes1(vector<int>& nums) {
        int cur = 0, mx = 0;
        for(int i=0; i<nums.size(); i++){
            nums[i] == 1 ? mx = max( ++cur, mx ) : cur = 0;
        }
        return mx;
    }
};

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    Solution nub; 
    cout<<nub.findMaxConsecutiveOnes(v);
    return 0;
}