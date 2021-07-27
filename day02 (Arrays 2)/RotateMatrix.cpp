#include <bits/stdc++.h>
using namespace std;

// reverse top down, and transpose
void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < i; ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}