// Last updated: 11/05/2026, 01:33:33
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int p = nums[0];
        for (int i = 1; i < nums.size(); i++){
            p ^= nums[i];
        }
        return p;
    }
};