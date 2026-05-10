// Last updated: 11/05/2026, 01:31:12
class Solution {
    public int findFinalValue(int[] nums, int original) {
        for(int i = 0; i < nums. length; i++){
            if(nums[i] == original){
                original = 2*original;
                i = -1;
            }
        }
        return original;
    }
}