class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i = nums.size()-2; i >= 0; i--){
            if (nums[i+1] > nums[i]){ index = i; break;}
        }
        if (index == -1){
            reverse(nums.begin(), nums.end());
        }
        else{
            int small = index+1;
            for (int i = index+1; i < nums.size(); i++){
                if (nums[i] <= nums[small] && nums[i] > nums[index]) small = i;
            }
            swap(nums[index], nums[small]);
            reverse(nums.begin()+index+1, nums.end());
        }
    }
};