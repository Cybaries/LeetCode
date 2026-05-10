// Last updated: 11/05/2026, 01:32:47
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        vector<int> vect;
        for(int i: nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>> q;
        for (auto x: mp){
            q.push({x.second,x.first});
        }
        while(k>0){
            vect.push_back(q.top().second);
            q.pop();
            k--;
        }
        return vect;
    }
};