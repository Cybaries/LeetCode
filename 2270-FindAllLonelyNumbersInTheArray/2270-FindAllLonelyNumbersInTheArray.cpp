// Last updated: 11/05/2026, 01:31:09
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n= nums.size();
        if (n <= 1)
            return nums;
        sort(nums.begin(),nums.end());
        vector<int> v;
        if (nums[1]-1 != nums[0] && nums[1] != nums[0])
            v.push_back(nums[0]);
        for (int i = 1; i < n-1; i++){
            if (nums[i-1] + 1 != nums[i] && nums[i+1] - 1 != nums[i] && nums[i-1] != nums[i] && nums[i+1] != nums[i])
                v.push_back(nums[i]);
        }
        if (nums[n-2]+1 != nums[n-1] && nums[n-2] != nums[n-1])
            v.push_back(nums[n-1]);
        return v;
    }
};