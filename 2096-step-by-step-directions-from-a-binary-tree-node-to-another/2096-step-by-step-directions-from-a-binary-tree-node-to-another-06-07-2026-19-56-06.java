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
    public String getDirections(TreeNode root, int startValue, int destValue) {
        TreeNode lca = dfs(root, startValue, destValue);
        StringBuilder s = new StringBuilder();
        findPath(lca, startValue, s);
        for (int i = 0; i < s.length(); i++){
            s.replace(i, i+1, "U");
        }
        findPath(lca, destValue, s);

        return s.toString();
    }

    private TreeNode dfs(TreeNode node, int start, int end) {
        if (node == null || node.val == start || node.val == end)
            return node;

        TreeNode left = dfs(node.left, start, end);
        TreeNode right = dfs(node.right, start, end);

        if (left != null && right != null)
            return node;

        return left != null ? left : right;
    }

    private boolean findPath(TreeNode node, int target, StringBuilder path) {
        if (node == null)
            return false;
        if (node.val == target)
            return true;

        // Try going left
        path.append("L");
        if (findPath(node.left, target, path))
            return true;
        path.deleteCharAt(path.length() - 1); // Backtrack if left was a dead end!

        // Try going right
        path.append("R");
        if (findPath(node.right, target, path))
            return true;
        path.deleteCharAt(path.length() - 1); // Backtrack if right was a dead end!

        return false; // Not found in this branch
    }
}