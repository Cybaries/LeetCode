class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zero = 0, one = 0, two = 0;
       for (int i : nums){
        if (i == 0) zero++;
        else if (i == 1) one++;
        else two++;
       }
       int start = 0;
       while(zero){
        nums[start++] = 0;
        zero--;
       }
       while(one){
        nums[start++] = 1;
        one--;
       }
       while(two){
        nums[start++] = 2;
        two--;
       }
    }
};