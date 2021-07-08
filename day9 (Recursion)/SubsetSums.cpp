#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        sort(arr.begin(), arr.end());
        genSubsetSum(arr, N, ans, 0, 0);
        return ans;
    }
    
    void genSubsetSum(vector<int> arr, int N, vector<int> &ans, int ind, int sum){
        if(ind==N){
            ans.push_back(sum);
            return;
        }
        // consider current element
        genSubsetSum(arr, N, ans, ind+1, sum);
        // or don't consider current element
        genSubsetSum(arr, N, ans, ind+1,sum+arr[ind]);
    }
};