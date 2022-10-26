class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> n(1001,0);
        vector<int> p(1001,0);
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <0)
                n[abs(nums[i])]++;
            else
                p[nums[i]]++;
        }
        for (int i = 1000; i >= 0; i--)
            if (p[i] && n[i])
                return i;
        return -1;
    }
};