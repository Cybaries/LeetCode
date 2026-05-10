// Last updated: 11/05/2026, 01:33:45
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res = true;
    int dfs(TreeNode* root, bool& ans){
       if (root){
           int left = dfs(root->left, ans);
           int right = dfs(root->right, ans);
           if (abs(left-right) > 1)
               ans = false;
           return 1 + max(left, right);
       }
        return 0;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool x = true;
        dfs(root, x);
        return x;
    }
};