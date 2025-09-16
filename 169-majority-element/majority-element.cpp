class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int element = nums[0];
        for (int i: nums){
            if (cnt == 0 || element == i){
                element = i;
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return element;

    }
};