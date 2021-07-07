#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        // binary search on lower size array 
        if( n1 > n2 ) return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = n1;
        
        while( lo<=hi ){
            
            // no of elements in left side of cut
            int cut1 = (lo + hi)>>1;
            int cut2 = ((n1+n2)>>1) - cut1;
            // cout<<"cut1: "<<cut1<<" cut2: "<<cut2<<"\n";
            
            int l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            
            int r1 = cut1==n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2==n2 ? INT_MAX : nums2[cut2];
            
            // cout<<lo<<hi<<cut1<<cut2<<l1<<l2<<r1<<r2<<"\n";
            
            // l1 > r2 ignore right half 
            if(l1 > r2) hi = cut1 - 1;
            
            // r1 < l2 ignore left half
            else if(r1 < l2) lo = cut1 + 1;
            
            // we got the required cut
            else return (n1+n2)&1 ? min(r1,r2) : (max(l1,l2) + min(r1,r2))/2.0;
                
        }
        
        return 0.0;
        
    }
};

int main() {
    int n1, n2, x;
    cin>>n1>>n2;
    vector<int> v1, v2;
    while(n1--){
        cin>>x;
        v1.push_back(x);
    }
    while(n2--){
        cin>>x;
        v2.push_back(x);
    }
    // for(auto it : v1) cout<<it<<" ";
    // cout<<"\n";
    // for(auto it : v2) cout<<it<<" ";
    // cout<<"\n";
    Solution nub;
    double ans = nub.findMedianSortedArrays(v1, v2);
    cout<<ans;
	return 0;
}