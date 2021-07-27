#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxLen(int A[], int n)
{
    // In practice, if memory is no issue, 
    // unordered_map is always faster if you want single element access.
    // to store the prefix sums
    unordered_map<int, int> m;
    int mx = 0, s = 0;
    for(int i=0; i<n; i++){
        s += A[i];
        if(s == 0) mx = i+1;
        else{
            if( m.find(s) == m.end() ){
                // first time occured
                // store the index with prefix sum as a value
                m[s] = i;
            }else{
                // exists already, calculate the length, update mx 
                mx = max(mx, i - m[s]);
            }
        }
        
    }
    return mx;
    
}