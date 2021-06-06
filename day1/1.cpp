#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        if(nums.size()==1) return;
        int lo = 0, mid = 0, hi = nums.size()-1;
        //before lo, all are zeros
        //after hi all are 2
        //operation starts from mid
        while(mid<=hi){
            switch(nums[mid]){
                case 0: //put it before lo
                    swap(nums[mid++], nums[lo++]);
                    break;
                case 1: //nothing to do
                    mid++;
                    break;
                case 2: //put it after hi
                    swap(nums[mid], nums[hi--]);
                    break;
            }
        }
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
    nub.sortColors(v);
    rep(i,n) cout<<v[i]<<" ";
	return 0;
}