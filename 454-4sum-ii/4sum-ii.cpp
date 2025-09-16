class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> ct;
        ct.reserve(n * n * 2);       // reserve space to avoid rehash
        ct.max_load_factor(0.7);     // reduce collisions
        
        for (int a : nums1) {
            for (int b : nums2) {
                ct[a + b]++;
            }
        }

        int total_ct = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                auto it = ct.find(-(c + d));
                if (it != ct.end()) {
                    total_ct += it->second;
                }
            }
        }
        return total_ct;
    }
};