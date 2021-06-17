#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*You are required to complete this function*/
int maxLen(int A[], int n)
{
    // Your code here
    // In practice, if memory is no issue, 
    // unordered_map is always faster if you want single element access.
    unordered_map<int, int> m;
    int mx = 0, s = 0;
    for(int i=0; i<n; i++){
        s += A[i];
        if(s == 0) mx = i+1;
        else{
            if( m.find(s) == m.end() ){
                m[s] = i;
            }else{
                mx = max(mx, i - m[s]);
            }
        }
        
    }
    return mx;
    
}