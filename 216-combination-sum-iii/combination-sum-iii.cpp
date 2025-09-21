class Solution {
public:
    void dfs(int index, vector<int>& nums, int k, int n, vector<int>& path, vector<vector<int>>& res){
        if (n == 0 && k == 0){
            res.push_back(path);
            return;
        }
        if (k == 0 || n < 0 || index == nums.size()) return;
        //Include element
        path.push_back(nums[index]);
        dfs(index+1, nums, k-1, n - nums[index], path, res);
        //Exclude element
        path.pop_back();
        dfs(index+1, nums, k, n, path, res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> path;
        vector<vector<int>> res;
        dfs(0, nums, k, n, path, res);
        return res;
    }
};