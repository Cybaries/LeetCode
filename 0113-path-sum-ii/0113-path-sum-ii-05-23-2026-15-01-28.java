class Solution {

    void helper(TreeNode root,
                int targetSum,
                int currsum,
                List<Integer> sublist,
                List<List<Integer>> list) {

        if (root == null) return;

        // choose
        sublist.add(root.val);

        // currsum += root.val;

        // leaf node
        if (root.left == null &&
            root.right == null &&
            currsum + root.val == targetSum) {

            list.add(new ArrayList<>(sublist));
        }

        // recurse
        helper(root.left, targetSum, currsum+root.val, sublist, list);

        helper(root.right, targetSum, currsum+root.val, sublist, list);

        // backtrack
        sublist.remove(sublist.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {

        List<List<Integer>> list = new ArrayList<>();

        helper(root, targetSum, 0,new ArrayList<>(), list);

        return list;
    }
}