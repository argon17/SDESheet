#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> dp(W+1, 0);
       for(int i=0; i<n; ++i){
           for(int j=W; j>=wt[i]; --j){
               dp[j] = max(dp[j], val[i] + dp[j-wt[i]]);
           }
       }
       return dp[W];
    }
};
