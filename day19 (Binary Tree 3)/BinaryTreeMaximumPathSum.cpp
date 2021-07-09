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
private:
    int mx;
public:
    int maxPathSum(TreeNode* root) {
        mx = INT_MIN;
        maxStSum(root);
        return mx;
    }
    int maxStSum(TreeNode* root){
        if(!root) return 0;
        int l = max(0, maxStSum(root->left)), r = max(0, maxStSum(root->right));
        mx = max(mx, root->val + l + r);
        return root->val + max(l, r);
    }
};