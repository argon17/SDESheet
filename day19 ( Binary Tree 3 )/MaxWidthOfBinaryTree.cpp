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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while(q.size()){
            int mn = q.front().second;
            int sz = q.size();
            int here;
            while(sz--){
                TreeNode* cur = q.front().first;
                int ind = q.front().second - mn;
                q.pop();
                if(cur->left) q.push({cur->left, ind*2});
                if(cur->right) q.push({cur->right, ind*2+1});
                here = ind + 1;
            }
            ans = max(ans, here);
        }
        return ans;
    }
};