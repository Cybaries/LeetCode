class Solution {
    public int[] leftRightDifference(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int sum = 0;
        for (int i: nums){
            sum += i;
        }
        int temp = 0;
        for (int i = 0; i < n; i++){
            ans[i] = Math.abs(temp - (sum - temp - nums[i]));
            temp += nums[i];
        }
        return ans;
    }
}