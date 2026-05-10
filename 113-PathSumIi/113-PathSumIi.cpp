// Last updated: 11/05/2026, 01:33:41
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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, vector<int>&path, int targetSum){
        if (root == nullptr) return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->right == nullptr && root->left == nullptr){
            if (targetSum == 0)
                ans.push_back(path);
        }
        else{
            dfs(root->left, path, targetSum);
            dfs(root->right, path, targetSum);
        }
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, path, targetSum);
        return ans;
    }
};