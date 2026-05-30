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
    public int widthOfBinaryTree(TreeNode root) {
        int val = 0;
        if (root == null)
            return val;

        Queue<TreeNode> q = new LinkedList<>();
        Queue<Long> indexQ = new LinkedList<>(); // ADD: parallel index queue

        q.offer(root);
        indexQ.offer(0L); // CHANGE: seed index at 0
        val = 1;

        while (!q.isEmpty()) {
            int size = q.size();
            long base = indexQ.peek(); // ADD: normalize each level to prevent overflow
            long first = 0, last = 0; // ADD: track leftmost and rightmost index

            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                long idx = indexQ.poll() - base; // ADD: normalized index

                if (i == 0)
                    first = idx; // ADD: leftmost node of this level
                if (i == size - 1)
                    last = idx; // ADD: rightmost node of this level

                if (node.left != null) { // KEEP: only non-null children
                    q.offer(node.left);
                    indexQ.offer(2 * idx); // ADD: left child index = 2 * parent
                }
                if (node.right != null) { // KEEP: only non-null children
                    q.offer(node.right);
                    indexQ.offer(2 * idx + 1); // ADD: right child index = 2 * parent + 1
                }
            }

            val = Math.max(val, (int) (last - first + 1)); // CHANGE: width = index span
        }
        return val;
    }
}