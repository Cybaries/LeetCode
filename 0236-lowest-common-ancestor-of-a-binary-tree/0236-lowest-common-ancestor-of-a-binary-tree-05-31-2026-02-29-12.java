/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        // Case 1 & 2: base cases — null means nothing found, returning p/q means target found
        if (root == null || root == p || root == q)
            return root;

        // Post-order: ask children first before deciding anything at this node
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        // Case 3a: p found in one subtree, q found in the other → THIS node is LCA
        if (left != null && right != null)
            return root;

        // Case 3b: both in same subtree → pass up whichever side found something
        return left != null ? left : right;
    }
}