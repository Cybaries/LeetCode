// Last updated: 11/05/2026, 01:31:06
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        for(int i = 0; i < nums. size(); i++){
            if(nums[i] == original){
                original = 2*original;
                i = -1;
            }
        }
        return original;
    }
};