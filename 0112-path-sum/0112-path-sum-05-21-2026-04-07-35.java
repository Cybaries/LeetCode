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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null)
            return false;
        Deque<TreeNode> deque = new ArrayDeque<>();
        deque.push(root);
        while (!deque.isEmpty()) {
            TreeNode node = deque.pop();
            if (node.left == null && node.right == null) {
                if (node.val == targetSum)
                    return true;
            }
            if (node.right != null) {
                node.right.val += node.val; 
                deque.push(node.right);
            }
            if (node.left != null) {
                node.left.val += node.val;
                deque.push(node.left);
            }
        }
        return false;
    }
}