// Last updated: 11/05/2026, 01:29:46
class Solution {
    public int[] countOppositeParity(int[] nums) {
        int[] res = new int[nums.length];

        for (int i = 0; i < nums.length; i++){
            int curr = nums[i];
            boolean flag = true;
            if (curr % 2 == 1) flag = false;
            int cnt = 0;
            for (int j = i+1; j < nums.length; j++){
                if (flag == true){
                    if (nums[j] % 2 == 1) cnt++;
                }
                else{
                    if (nums[j] % 2 == 0) cnt++;
                }
            }
            res[i] = cnt;
        }
        return res;
    }
}