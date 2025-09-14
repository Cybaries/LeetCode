class Solution {
public:
    void dfs(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& res){
        if (index == nums.size()){
            res.push_back(path);
            return;
        }
        //Include
        path.push_back(nums[index]);
        dfs(index+1, nums, path, res);
        path.pop_back();
        //Exclude + skip similar occurrences since we're excluding this
        while (index < nums.size()-1 && nums[index] == nums[index+1]){
            index++;
        }
        dfs(index+1, nums, path, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> res;
        dfs(0, nums, path, res);
        return res;
    }
};