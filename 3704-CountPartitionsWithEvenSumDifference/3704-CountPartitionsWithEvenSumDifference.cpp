// Last updated: 11/05/2026, 01:30:12
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0, cnt = 0;
        for (int i: nums) total+= i;
        int pointer = 0, sum = 0;
        while (pointer < nums.size()-1){
            sum += nums[pointer];
            total -= nums[pointer];
            if (abs(total - sum) % 2 == 0) cnt++;
            pointer++;
        }
        return cnt;
    }
};