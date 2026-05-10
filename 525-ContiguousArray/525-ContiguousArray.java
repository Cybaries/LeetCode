// Last updated: 11/05/2026, 01:32:27
class Solution {
    public int findMaxLength(int[] nums) {
        // 0 1 1 0
        // 0 1 0 0 1
        // 
        int n = nums.length;
        int[] arr = new int[2 * n + 1];
        Arrays.fill(arr, -1);
        arr[n] = 0;
        int sum = n, max = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            if (arr[sum] != -1) {
                max = Math.max(max, i + 1 - arr[sum]);
            } else {
                arr[sum] = i + 1;
            }
        }
        return max;
    }
}