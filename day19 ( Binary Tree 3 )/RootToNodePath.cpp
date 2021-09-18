// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool go(TreeNode* rt, int n, vector<int> &ans){
    if(!rt) return 0;
    ans.push_back(rt->val);
    if(rt->val == n) return 1;
    if(go(rt->left, n, ans) || go(rt->right, n, ans)) return 1;
    ans.pop_back();
    return 0;
}
vector<int> solve(TreeNode* A, int B) {
    vector<int> ans;
    go(A, B, ans);
    return ans;
}