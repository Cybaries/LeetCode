class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, bool> mp;
        for (int i: nums) mp[i] = true;
        int longest = 0;
        for (auto i: mp){
            int num = i.first;
            if (!mp.count(num -1)){
                int currNum = num;
                int cnt = 1;
                while (mp.count(currNum+1)){
                    currNum++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};