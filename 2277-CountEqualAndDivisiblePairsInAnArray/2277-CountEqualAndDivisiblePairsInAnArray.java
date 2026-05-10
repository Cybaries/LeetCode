// Last updated: 11/05/2026, 01:31:02
class Solution {
    public int countPairs(int[] nums, int k) {
         int l = nums.length;
        int res = 0; int count = 0;
        for(int i = 0; i < l-1 ; i++){
            for(int j = i+1; j < l; j++){
                if(nums[i] == nums[j] ){
                    res = i*j;
                    if(res%k==0)
                      count++;
                }
                
            }
        }
        return count;
    }
}