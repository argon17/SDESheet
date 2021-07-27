#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int mx = 0;
        int n = heights.size();
        for (int i = 0; i <= n; ++i)
        {
            while (st.size() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                mx = max(mx, width * height);
            }
            st.push(i);
        }
        return mx;
    }
};