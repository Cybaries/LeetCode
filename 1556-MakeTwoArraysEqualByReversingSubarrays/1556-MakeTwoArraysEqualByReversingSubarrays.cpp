// Last updated: 11/05/2026, 01:31:44
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> nums(1001);
        for(int i: target){
            nums[i-1]++;
        }
        for(int i: arr) nums[i-1]--;
        for(int i: nums){
            if (i) return false;
        }
        return true;
    }
};