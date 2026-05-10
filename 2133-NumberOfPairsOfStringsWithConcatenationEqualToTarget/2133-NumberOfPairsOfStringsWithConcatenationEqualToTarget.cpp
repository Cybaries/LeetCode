// Last updated: 11/05/2026, 01:31:31
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0;
        for (int i=0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if (nums[i]+nums[j] == target && i!=j){
                    count++;
                    // cout << i << " " << j<<endl;
                }
                
            }
        }
        return count;
    }
};