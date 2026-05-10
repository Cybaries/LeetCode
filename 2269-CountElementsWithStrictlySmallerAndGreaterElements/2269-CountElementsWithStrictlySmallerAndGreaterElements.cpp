// Last updated: 11/05/2026, 01:31:13
class Solution {
public:
    int countElements(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        int res = 0;
        
        for(int x: nums){
            if(min < x && max > x) res++;
        }
        
        return res;
    }
};