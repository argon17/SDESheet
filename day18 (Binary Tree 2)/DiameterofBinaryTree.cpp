#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// O(n) solution
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return dfs(root).first;
    }

private:
    // {diameter, height}
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        pair<int, int> l = dfs(root->left), r = dfs(root->right);
        return {max({l.first, r.first, l.second + r.second}), 1 + max(l.second, r.second)};
    }
};