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
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) return 0;

        // Paths starting at root  +  paths in left subtree  +  paths in right subtree
        return countFrom(root, targetSum)
             + pathSum(root.left,  targetSum)
             + pathSum(root.right, targetSum);
    }

    // Count all downward paths starting exactly from 'node' that sum to 'remaining'
    private int countFrom(TreeNode node, long remaining) {
        if (node == null) return 0;

        int found = (node.val == remaining) ? 1 : 0;
        found += countFrom(node.left,  remaining - node.val);
        found += countFrom(node.right, remaining - node.val);
        return found;
    }
}