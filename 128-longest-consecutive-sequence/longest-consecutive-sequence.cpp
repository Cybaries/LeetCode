class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, bool> mp;
        for (int num : nums) {
            mp[num] = true;
        }

        int longest = 0;

        for (auto& pair : mp) {
            int num = pair.first;

            // Check if `num` is the start of a sequence
            if (!mp.count(num - 1)) {
                int currentNum = num;
                int cnt = 1;

                // Count the length of the consecutive sequence
                while (mp.count(currentNum + 1)) {
                    currentNum++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
