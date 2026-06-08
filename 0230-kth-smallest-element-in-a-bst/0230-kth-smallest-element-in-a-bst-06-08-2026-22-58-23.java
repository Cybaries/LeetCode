/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int val= -1;
    private int cnt = 0;
    public int kthSmallest(TreeNode root, int k) {
        dfs(root, k);
        return val;
    }

    private int dfs(TreeNode node, int k){
        if (node == null) return -1;

        dfs(node.left, k);
        cnt++;
        if (k == cnt) val = node.val;
        dfs(node.right, k);
        return node.val;
    }
}