// Last updated: 11/05/2026, 01:30:51
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] == key){
                if (mp[nums[i+1]] == NULL)
                    mp[nums[i+1]] = 1;
                else
                    mp[nums[i+1]]++;
            }
        }
        int mx = 0;
        int target = 0;
        for (auto i: mp){
            // cout<<i.first<<" "<<i.second;
            if (i.second > mx){
                target = i.first;
                mx = i.second;
            }
        }
        return target;
    }
};