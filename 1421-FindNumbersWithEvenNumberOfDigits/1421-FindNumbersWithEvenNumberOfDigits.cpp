// Last updated: 11/05/2026, 01:31:46
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int i: nums){
            if (to_string(i).size() %2 == 0)
                cnt++;
        }
        return cnt;
    }
};