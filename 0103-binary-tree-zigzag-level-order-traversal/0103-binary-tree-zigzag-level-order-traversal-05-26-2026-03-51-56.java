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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        boolean leftToRight = true;

        while (!q.isEmpty()) {
            int size = q.size();
            LinkedList<Integer> level = new LinkedList<>();  // LinkedList supports addFirst

            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();

                // Direction only affects WHERE in the list we insert — not which child we enqueue
                if (leftToRight) {
                    level.addLast(node.val);   // L→R: append to back
                } else {
                    level.addFirst(node.val);  // R→L: prepend to front = reverse display
                }

                // Always enqueue left then right — queue order stays predictable
                if (node.left  != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }

            res.add(level);
            leftToRight = !leftToRight;  // flip ONCE, OUTSIDE the loop
        }
        return res;
    }
}