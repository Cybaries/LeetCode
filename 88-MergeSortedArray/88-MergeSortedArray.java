// Last updated: 11/05/2026, 01:33:56
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(n == 0)
            return;
        for (int i = 0; i < n; i++){
            nums1[i+m] = nums2[i];                //n
        }
        Arrays.sort(nums1);
    }
}