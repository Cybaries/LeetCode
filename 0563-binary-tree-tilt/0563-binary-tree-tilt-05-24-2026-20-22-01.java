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
    private List<Integer> tilts = new ArrayList<>();
    public int findTilt(TreeNode root) {
        int sm = 0;
        dfs(root);
        for (int x: tilts)
            sm += x;

        return sm;
    }

    private int dfs(TreeNode node){
        if (node == null) return 0;

        int leftH = dfs(node.left);
        int rightH = dfs(node.right);

        int tilt = Math.abs( leftH - rightH);
        tilts.add(tilt);

        return node.val + leftH + rightH;
    }
}