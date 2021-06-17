#include<bits/stdc++.h>
using namespace std;

struct combo{
        int start;
        int end;
        int profit;
};
bool cmp(combo a, combo b){
    return a.end < b.end;
}
class Solution {
public:
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = endTime.size();
        int dp[n];
        vector<combo> info(n);
        
        for(int i = 0; i < n; i++){
            info[i].start = startTime[i];
            info[i].end = endTime[i];
            info[i].profit = profit[i];
        }
        
        sort(info.begin(), info.end(), cmp);
        // dp[i] : max profit till endTime[i]
        dp[0] = info[0].profit;
        for(int i = 1; i < n; i++){
            
            // dp[i] =  max(dp[i-1], current profit or info[i].profit +  profit before this work(p) or dp[such endTime which last before current startTime])
            int p = 0;
            for(int j = i - 1; j >= 0; j--){
                if(info[j].end <= info[i].start){
                    p = dp[j];
                    break;
                }
            }
            dp[i] = max(dp[i-1], info[i].profit + p );
        }
        return dp[n-1];
    }
};