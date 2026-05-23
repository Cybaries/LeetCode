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
    private int maxDiameter = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        height(root);
        return maxDiameter;
    }

    private int height(TreeNode node) {
        if (node == null) return 0; // null contributes 0 edges

        int leftH  = height(node.left);
        int rightH = height(node.right);

        // Longest path THROUGH this node = edges going left + edges going right
        maxDiameter = Math.max(maxDiameter, leftH + rightH);

        // Height returned to parent = 1 edge to this node + best subtree below
        return 1 + Math.max(leftH, rightH);
    }
}