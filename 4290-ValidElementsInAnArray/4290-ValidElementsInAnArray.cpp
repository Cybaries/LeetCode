// Last updated: 11/05/2026, 01:29:55
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> res;
        if (nums.size() <= 2) return nums;
        int highLeft = nums[0];
        int highLeftIndex = 0;
        int highRight = nums[nums.size()-1];
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size()-1; i++){
            if (nums[i] > highLeft){
                res.push_back(nums[i]);
                highLeft = nums[i];
                highLeftIndex = i;
            }
        }
        vector<int> temp;
        for (int i = nums.size()-2; i > highLeftIndex; i--){
            if (nums[i] > highRight){
                temp.push_back(nums[i]);
                highRight = nums[i];
            }
        }
        for (int i = temp.size()-1; i >= 0; i--){
            res.push_back(temp[i]);
        }
        res.push_back(nums[nums.size()-1]);
        return res;
    }
};