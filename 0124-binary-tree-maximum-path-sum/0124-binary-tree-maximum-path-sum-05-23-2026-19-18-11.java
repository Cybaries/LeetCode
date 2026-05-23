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
    private int maxSum = Integer.MIN_VALUE; // handles all-negative trees

    public int maxPathSum(TreeNode root) {
        dfs(root);
        return maxSum;
    }

    private int dfs(TreeNode node) {
        if (node == null) return 0;

        // Max gain from each subtree — clamp to 0 if negative (don't extend)
        int leftGain  = Math.max(0, dfs(node.left));
        int rightGain = Math.max(0, dfs(node.right));

        // Role 1: treat this node as the turning point of a path
        // left subtree → node → right subtree (complete, not passed upward)
        int pathThroughNode = node.val + leftGain + rightGain;
        maxSum = Math.max(maxSum, pathThroughNode);

        // Role 2: return the best single-arm gain to the parent
        // parent can only use ONE direction, so pick the better side
        return node.val + Math.max(leftGain, rightGain);
    }
}