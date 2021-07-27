#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool comp(Item a, Item b)
{
    return (double)a.value / (double)a.weight > (double)b.value / (double)b.weight;
}

class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comp);
        double ans = 0;
        int i = 0;
        while (W > 0 && i < n)
        {
            if (W >= arr[i].weight)
                ans += arr[i].value, W -= arr[i].weight;
            else
            {
                double fr = W / (double)arr[i].weight;
                ans += fr * arr[i].value, W -= fr * arr[i].weight;
            }
            ++i;
        }
        return ans;
    }
};