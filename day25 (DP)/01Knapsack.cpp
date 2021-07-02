#include<bits/stdc++.h>
using namespace std;


// standard 0/1 knapsack with O(n*n) SC
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        int dp[n + 1][W + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= W; ++j) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else {

                    if (j >= wt[i - 1])
                        dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);

                    else dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
};


// 0/1 optimized knapsack with O(n) SC
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
