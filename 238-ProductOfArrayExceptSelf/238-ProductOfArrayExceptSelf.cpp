// Last updated: 11/05/2026, 01:33:00
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> v;
        int product = 1;
        int count = 0;
        for (int x: nums){
            if (x == 0)
                count++;
            else
                product *= x;
        }
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                fill(nums.begin(),nums.end(),0);
                if (count >1)
                    break;
                nums[i] = product;
                break;
            }
            nums[i] = product/nums[i];
        }
        return nums;
    }
};