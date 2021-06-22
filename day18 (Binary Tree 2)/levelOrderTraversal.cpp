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

/* BFS Idea */

// take out node from queue, perform operation, push their child to the queue

// take out nodes from queue currrent q.size() no of times
// because q size will be increasing in future, as we'll be pushing their child too

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int size = q.size();
            vector<int> level;

            // iterate over current level nodes, keep storing the values in level vector
            // keep popping the current level nodes
            // also keep pushing child nodes into the queue

            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};