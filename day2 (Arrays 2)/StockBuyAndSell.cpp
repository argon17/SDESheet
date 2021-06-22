#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
    int mn = 1e9, profit = 0;
    // keep track of min till here
    // keep updating profit wrt current min
    for(int price : prices){
        mn = min(mn, price);
        profit = max(price-mn, profit);
    }
    return profit;
}