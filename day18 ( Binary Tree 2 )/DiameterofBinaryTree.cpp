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
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        dfs(root, diam);
        return diam;
    }
private:
    int dfs(TreeNode* root, int &diam){
        if(!root) return 0;
        int lh = dfs(root->left, diam);
        int rh = dfs(root->right, diam);
        diam = max(diam, lh + rh);
        return 1 + max(lh, rh);
    }
};