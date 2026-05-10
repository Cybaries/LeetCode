// Last updated: 11/05/2026, 01:33:57
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt (3,0);
        for (int i: nums) cnt[i]++;
        int index = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < cnt[i]; j++){
                nums[index++] = i;
            }
        }
    }
};