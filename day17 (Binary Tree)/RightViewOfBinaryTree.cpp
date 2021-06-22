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
// do a bfs and get last node of each level
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()){
        int size = q.size();
        TreeNode* cur;
        while(size--){
            cur = q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        ans.push_back(cur->val);
    }
    return ans;
}