// Last updated: 11/05/2026, 01:33:51
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        for (int i = 0; i < nums.size()-1;){
            // cout<< count <<" "<< nums[i] << " "<<nums[i+1]<<endl;
            if (nums[i] == nums[i+1] && count >=2){
                // cout<< count <<" "<< nums[i] << " "<<nums[i+1]
                nums.erase(nums.begin()+i+1);
            }
            else if (nums[i] == nums[i+1]){
                count++;
                i++;
            }
            else{
                count = 1;
                i++;
            }
        }
        return nums.size();
    }
};