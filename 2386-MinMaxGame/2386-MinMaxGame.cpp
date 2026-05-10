// Last updated: 11/05/2026, 01:30:36
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n/2; i++){
            if (i%2)
                nums[i] = max(nums[2*i], nums[2*i+1]);
            else
                nums[i] = min(nums[2*i], nums[2*i+1]);
        }
        vector<int> newNums(n/2);
        for (int i = 0; i < n/2; i++){
            // cout<<nums[i]<<" ";
            newNums[i] = nums[i];
        }
        // cout<<endl;
        return minMaxGame(newNums);
    }
};