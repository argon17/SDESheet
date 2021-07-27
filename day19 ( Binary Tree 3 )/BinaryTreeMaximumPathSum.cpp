#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int mx = -1e5;
public:
    int maxPathSum(TreeNode* root) {
        calc(root);
        return mx;
    }
    int calc(TreeNode *root){
        if(!root) return 0;
        // if leftMx / rightMx is negative, don't consider it.
        int leftMx = max(0, calc(root->left)), rightMx = max(0, calc(root->right));
        mx = max(mx, root->val + leftMx + rightMx);
        return root->val + max(leftMx, rightMx);
    }
};