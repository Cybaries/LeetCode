// Last updated: 11/05/2026, 01:30:45
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1; i < nums.size()-1; i++){
            cout<< nums[i]<<" "<<cnt<<endl;
            if (nums[i]<nums[i-1]){
                for(int j = i+1; j < nums.size()&&nums[j]>=nums[i]; j++){
                    if (nums[j] > nums[i]){
                        cnt++;
                        break;
                    }
                }
            }
            // cout<< nums[i]<<" "<<cnt<<endl;
            else if (nums[i]>nums[i-1]){
                for(int j = i+1; j < nums.size() && nums[j]<=nums[i]; j++){
                    if (nums[j] < nums[i]){
                        cnt++;
                        break;
                    }
                }
            }
            cout<< nums[i]<<" "<<cnt<<endl;
        }
        return cnt;
    }
};