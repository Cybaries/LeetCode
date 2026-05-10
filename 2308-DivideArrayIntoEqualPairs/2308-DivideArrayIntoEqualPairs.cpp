// Last updated: 11/05/2026, 01:30:48
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> v(502,0);
        // bool ans = true;
        for (int i: nums){
            v[i]++;
        }
        for(int i: v){
            if (i % 2){
                return false;
            }
        }
        return true;
    }
};