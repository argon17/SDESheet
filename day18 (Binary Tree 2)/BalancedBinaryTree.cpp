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

class Solution
{
private:
    bool ans = 1;

public:
    bool isBalanced(TreeNode *root)
    {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = dfs(root->left), rh = dfs(root->right);
        ans &= abs(lh - rh) < 2;
        return 1 + max(lh, rh);
    }
};