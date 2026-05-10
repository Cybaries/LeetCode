// Last updated: 11/05/2026, 01:30:05
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = nums.size()-1; i >= 0 && k; i--){
            if (ans.empty()){
                ans.push_back(nums[i]);
                k--;
                continue;
            }
            if (nums[i] != ans.back()){
                ans.push_back(nums[i]);
                k--;
            }
        }
        return ans;
    }
};