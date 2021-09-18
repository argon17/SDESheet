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
public:
    int maxPathSum(TreeNode* root) {
        int mx = -1e9;
        dfs(root, mx);
        return mx;
    }
private:
    int dfs(TreeNode* root, int &mx){
        if(!root) return 0;
        int lsum = max(0, dfs(root->left, mx));
        int rsum = max(0, dfs(root->right, mx));
        mx = max(mx, root->val + lsum + rsum);
        return root->val + max(lsum, rsum);
    }
};