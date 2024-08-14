class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            auto index = find(nums.begin()+i+1, nums.end(), target-nums[i]);
            if (index != nums.end()) return {i, (int)(index - nums.begin())};
        }
        return {};
    }
};