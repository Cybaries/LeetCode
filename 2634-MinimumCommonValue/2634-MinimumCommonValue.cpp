// Last updated: 11/05/2026, 01:30:19
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size();
        int n = nums2.size();
        while (i < m && j < n) {
            if (i > 0 && nums1[i] == nums1[i - 1]) {
                i++;
                continue;
            }
            if (nums1[i] < nums2[j])
                i++;
            else if (nums2[j] < nums1[i])
                j++;
            else if (nums2[j] == nums1[i])
            {
                return nums2[j];
            }
        }
        return -1;
    }
};