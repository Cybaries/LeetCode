class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -1e4-1;
        int sum = 0;
        int startIndex = 0, endIndex = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (sum > maxSum){
                maxSum = sum;
                endIndex = i;
            }
            if (sum < 0){
                sum = 0;
                startIndex = i+1, endIndex = i+1;
            }
        }
        // for (int i = startIndex; i <= endIndex; i++){
        //     cout<<nums[i]<<" ";
        // }
        return maxSum;
    }
};