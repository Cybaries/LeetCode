// Last updated: 11/05/2026, 01:30:28
class Solution
{
    public:
        int findMaxK(vector<int> &nums)
        {
            unordered_set<int> st(begin(nums), end(nums));
            int res = -1;
            for (int p: nums)
                if (p > 0 and st.count(-p)) res = max(res, p);
            return res;
        }
};