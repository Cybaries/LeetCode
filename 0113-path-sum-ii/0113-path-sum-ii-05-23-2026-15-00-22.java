class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Deque<TreeNode>      nodeDeque = new ArrayDeque<>();
        Deque<List<Integer>> pathDeque = new ArrayDeque<>();
        Deque<Integer>       sumDeque  = new ArrayDeque<>();

        // Seed all three deques with root's info
        List<Integer> rootPath = new ArrayList<>();
        rootPath.add(root.val);

        nodeDeque.push(root);
        pathDeque.push(rootPath);
        sumDeque.push(root.val);

        while (!nodeDeque.isEmpty()) {
            TreeNode     node       = nodeDeque.pop();
            List<Integer> path      = pathDeque.pop();
            int           currentSum = sumDeque.pop();
            // Leaf check: if sum matches, this path is valid
            if (node.left == null && node.right == null) {
                if (currentSum == targetSum) result.add(path);
            }
            // Push right first → left popped first → PreOrder: Root→Left→Right
            if (node.right != null) {
                List<Integer> rightPath = new ArrayList<>(path); // copy for this branch
                rightPath.add(node.right.val);

                nodeDeque.push(node.right);
                pathDeque.push(rightPath);
                sumDeque.push(currentSum + node.right.val);
            }
            if (node.left != null) {
                List<Integer> leftPath = new ArrayList<>(path);  // copy for this branch
                leftPath.add(node.left.val);

                nodeDeque.push(node.left);
                pathDeque.push(leftPath);
                sumDeque.push(currentSum + node.left.val);
            }
        }
        return result;
    }
}