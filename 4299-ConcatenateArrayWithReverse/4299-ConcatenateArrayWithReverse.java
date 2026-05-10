// Last updated: 11/05/2026, 01:29:47
class Solution {
    public int[] concatWithReverse(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n * 2];
        int i = 0;
        for (; i < n; i++){
            ans[i] = nums[i];
            ans[n * 2 - 1 - i] = nums[i];
        }
        return ans;
    }
}