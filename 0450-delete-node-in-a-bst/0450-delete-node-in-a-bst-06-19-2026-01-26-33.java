/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        // Base case: the key was not found or tree is empty
        if (root == null) return null;

        // 1. Search Phase: Traverse the BST to find the node
        if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } 
        else if (key > root.val) {
            root.right = deleteNode(root.right, key);
        } 
        // 2. Deletion Phase: We found the node! (key == root.val)
        else {
            // Case 1 & 2: The node is a leaf, or has exactly one child
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;

            // Case 3: The node has TWO children (The Trap)
            // A. Find the in-order successor (the smallest node in the right subtree)
            TreeNode successor = root.right;
            while (successor.left != null) {
                successor = successor.left;
            }

            // B. Copy the successor's value into the current node
            root.val = successor.val;

            // C. Recursively delete the original successor node from the right subtree
            root.right = deleteNode(root.right, successor.val);
        }
        
        // Return the explicitly updated node back up the recursion stack
        return root;
    }
}