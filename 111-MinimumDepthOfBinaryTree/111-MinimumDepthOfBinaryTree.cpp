// Last updated: 11/05/2026, 01:33:44
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
    int dfs(TreeNode* root){
        if (root){
            if (root->left == nullptr && root->right == nullptr)
            return 1;
            return 1 + min(dfs(root->left),dfs(root->right));
        }
        return 10005;
    }
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        return dfs(root);
        // return cnt;
    }
};