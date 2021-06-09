#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

// one soln will be sort and iterate and find where a[i] == a[i+1],
// but will end up modifying the array :(

// other approach could be to maintain a map, which contains frequency of elements
// but end up having O(n) SC

// here comes the floyd's cycle detection algorithm
// entry point of the cycle is the answer
// why? because there should be two indices to reach the duplicate
// which makes a cycle

class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow != fast ){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
    }
};



int main() {
    int n, tmp; cin>>n;
    vector<int> v;
    rep(i,n){
        cin>>tmp;
        v.push_back(tmp);
    }
    Solution nub;
    int ans = nub.findDuplicate(v);
    cout<<ans<<" ";
	return 0;
}