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
    private int cameras = 0;

    public int minCameraCover(TreeNode root) {
        // If root itself came back uncovered, place one camera there
        if (dfs(root) == 0) cameras++;
        return cameras;
    }

    // Returns: 0 = not covered, 1 = covered (no camera), 2 = has camera
    private int dfs(TreeNode node) {
        if (node == null) return 1; // null is treated as "covered" — no camera needed

        int left  = dfs(node.left);
        int right = dfs(node.right);

        // Any child is NOT covered → MUST place camera here to cover it
        if (left == 0 || right == 0) {
            cameras++;
            return 2; // this node now has a camera
        }

        // Any child HAS a camera → that camera covers this node
        if (left == 2 || right == 2) {
            return 1; // covered by child, no camera needed here
        }

        // Both children are covered but neither has a camera
        // → nothing covers this node, let parent handle it
        return 0; // not covered
    }
}