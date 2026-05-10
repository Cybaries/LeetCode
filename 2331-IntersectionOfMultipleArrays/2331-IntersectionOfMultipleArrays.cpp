// Last updated: 11/05/2026, 01:30:44
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> v;
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                // cout<< i << " "<<j<<endl;
                mp[nums[i][j]]++;
                // cout<<"Hello"<<endl;
            }
        }
        for (auto i = mp.begin(); i != mp.end(); i++){
            // cout << i-> first <<" "<<i-> second;
            if (i->second == nums.size())
                v.push_back(i->first);
        }
        sort(v.begin(),v.end());
        return v;
    }
};