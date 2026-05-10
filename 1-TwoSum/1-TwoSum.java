// Last updated: 11/05/2026, 01:34:47
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        boolean flag = false;
        for (int i = 0; i < nums.length-1;i++){
            int find = target - nums[i];
            for (int j = i+1; j < nums.length; j++){
                if (nums[j] == find){
                    res[0] = i;
                    res[1] = j;
                    flag = true;
                    break;
                }
            }
            if (flag == true) break;
        }
        return res;
    }
}