class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, mx = 0;
        nums.push_back(0);
        for (int i: nums){
            if (i == 1)
                cnt++;
            else{
                mx = max(mx,cnt);
                cnt = 0;
            }
        }
        return mx;
    }
};