// Last updated: 11/05/2026, 01:30:34
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        nums.push_back(-1e5);
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int mx = nums[nums.size()-1];
        for (int i = nums.size()-1; i > 0; i--){
            // cout<< cnt <<" "<<mx<<" "<< nums[i]<<endl;
            if (mx - nums[i-1] > k){
                mx = nums[i-1];
                cnt++;
            }
        }
        // if (nums[0] != mx)
        //     cnt++;
        return cnt;
    }
};