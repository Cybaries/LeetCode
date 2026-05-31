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

    // Pair carries: LCA of deepest leaves in this subtree + depth of those leaves
    static class Pair {
        TreeNode node;
        int depth;

        Pair(TreeNode node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).node;
    }

    private Pair dfs(TreeNode node) {
        if (node == null)
            return new Pair(null, 0); // null contributes depth 0

        Pair left = dfs(node.left);
        Pair right = dfs(node.right);

        if (left.depth == right.depth) {
            // Deepest leaves are equally deep on both sides
            // → this node is their LCA
            return new Pair(node, left.depth + 1);

        } else if (left.depth > right.depth) {
            // Deepest leaves all live in the left subtree
            // → bubble up left's LCA
            return new Pair(left.node, left.depth + 1);

        } else {
            // Deepest leaves all live in the right subtree
            // → bubble up right's LCA
            return new Pair(right.node, right.depth + 1);
        }
    }
}