#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> tmp;
            int x = 1;
            tmp.push_back(x);
            for(int j=0; j<i; j++){
                x = x * (i-j)/(j+1);
                tmp.push_back(x);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {
    int n; cin>>n;
    Solution nub;
    vector<vector<int>> ans = nub.generate(n);
    for(auto it1: ans){
        for(auto it2: it1) cout<<it2<<" ";
        cout<<"\n";
    }
	return 0;
}