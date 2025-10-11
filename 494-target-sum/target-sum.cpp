class Solution {
public:
    int dfs (int idx, int sum, int cnt, char currOper, vector<int>& nums, int target){
        if (idx >=nums.size()){
            if (sum == target){
                cnt++;
                return cnt;
            }
            else{
                return cnt;
            }
        }
        if (currOper == '+') sum += nums[idx];
        if (currOper == '-') sum -= nums[idx];

        return dfs(idx+1, sum, cnt, '+', nums, target) + dfs(idx+1, sum,cnt, '-', nums, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt =  dfs(0, 0, 0, '+', nums, target) + dfs(0, 0, 0, '-', nums, target);
        return cnt/2;
    }
};