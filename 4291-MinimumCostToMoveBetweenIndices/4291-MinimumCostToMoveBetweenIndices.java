// Last updated: 11/05/2026, 01:29:53
class Solution {
    public int[] minCost(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] closest = new int[n];

        for (int i = 0; i < n; i++) {
            int leftDiff = Integer.MAX_VALUE;
            int rightDiff = Integer.MAX_VALUE;
            
            if (i > 0) leftDiff = Math.abs(nums[i] - nums[i - 1]);
            if (i < n - 1) rightDiff = Math.abs(nums[i] - nums[i + 1]);
            
            if (leftDiff <= rightDiff) {
                closest[i] = i - 1;
            } else {
                closest[i] = i + 1;
            }
        }
        
        int[] forward = new int[n];

        for (int i = 1; i < n; i++) {
            int cost;            
            if (closest[i - 1] == i) {
                cost = 1;
            } else {
                cost = nums[i] - nums[i - 1];
            }
            forward[i] = forward[i - 1] + cost;
        }
        
        int[] backward = new int[n];
        
        for (int i = n - 2; i >= 0; i--) {
            int cost;
            if (closest[i + 1] == i) {
                cost = 1;
            } else {
                cost = nums[i + 1] - nums[i];
            }
            backward[i] = backward[i + 1] + cost;
        }
        
        int m = queries.length;
        int[] ans = new int[m];
        
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l < r) {
                ans[i] = forward[r] - forward[l];
            } else {
                ans[i] = backward[r] - backward[l];
            }
        }
        
        return ans;
    }
}