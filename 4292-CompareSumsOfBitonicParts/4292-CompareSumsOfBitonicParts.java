// Last updated: 11/05/2026, 01:29:52
class Solution {
    public int compareBitonicSums(int[] nums) {
        long ascSum = 0;
        long descSum = 0;
        if (nums.length == 1) return -1;
        for (int i = 1; i < nums.length; i++){
            if (nums[i] > nums[i-1])
                ascSum += nums[i-1];
            else{
                ascSum += nums[i-1];
                break;
            }
        }
        for (int i = nums.length-2; i >= 0; i--){
            if (nums[i] > nums[i+1])
                descSum += nums[i+1];
            else{
                descSum += nums[i+1];
                break;
            }
        }
        System.out.println(ascSum + " "+ descSum);
        if (ascSum > descSum)
            return 0;
        else if (descSum > ascSum)
            return 1;
        return -1;
    }
}