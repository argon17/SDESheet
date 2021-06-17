#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

class Solution 
{
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, cmp);
        int mxjobs = 0;
        // max jobs done can not be more than max deadline
        for(int i = 0; i < n; i++){
            mxjobs = max(mxjobs, arr[i].dead);
        }
        bool done[mxjobs] = {false};
        int day = 0, profit = 0;
        for(int i = 0; i < n; i++){
            // try filling it from right most side, easy :)
            // as job can only be done before deadline
            // preference is to do it at the last day possible;)
            // in order to do more work
            for(int j = arr[i].dead - 1; j >= 0; j--){
                if(!done[j]){
                    done[j] = true;
                    day += 1;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {day, profit};
    } 
};
