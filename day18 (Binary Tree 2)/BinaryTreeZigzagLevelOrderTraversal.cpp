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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool ltr = 1;
        while (q.size())
        {
            int sz = q.size();
            vector<int> levels(sz);
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *cur = q.front();
                q.pop();
                int ind = ltr ? i : sz - 1 - i;
                levels[ind] = cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ltr = 1 - ltr;
            ans.push_back(levels);
        }
        return ans;
    }
};