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
    int cnt = 0, ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        explore(root, k);
        return ans;
    }
    
    void explore(TreeNode* root, int &k){
        if(!root) return;
        explore(root->left, k);
        if(++cnt==k){
            ans = root->val;
            return;
        }
        explore(root->right, k);
    }
};