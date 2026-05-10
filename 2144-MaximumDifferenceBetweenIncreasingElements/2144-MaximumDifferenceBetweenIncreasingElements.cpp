// Last updated: 11/05/2026, 01:31:30
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int r=-1, min_ = nums[0];
        for (int j=1; j < nums.size(); j++){
                r= max(r, nums[j] - min_);
                min_=min(min_, nums[j]);
        }
        return (r>0?r:-1);
    }
};