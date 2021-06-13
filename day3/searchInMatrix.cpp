#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ro = matrix.size(), cl = matrix[0].size();
        int lo = 0, hi = ro*cl - 1;
        while(lo <= hi){
            int mid = (lo + hi)>>1;
            if(matrix[mid/cl][mid%cl] == target) return true;
            else if(matrix[mid/cl][mid%cl] < target) lo = mid+1;
            else hi = mid - 1;
        }
        return false;
    }
};