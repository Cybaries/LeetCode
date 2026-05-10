// Last updated: 11/05/2026, 01:32:53
class Solution {
    public int missingNumber(int[] nums) {
        int l,sum;
        l=nums.length;
        sum= l*(l+1)/2;
        for (int i:nums)
            sum-=i;
        return sum;
    }
}