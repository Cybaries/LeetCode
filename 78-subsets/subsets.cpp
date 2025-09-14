class Solution {
public:
    void dfs(int index, vector<int>& nums, vector<int>& path, vector<vector<int>>& res){
        if (index == nums.size()){
            res.push_back(path);
            return;
        }
        dfs(index+1,nums,path,res);
        path.push_back(nums[index]);
        dfs(index+1,nums,path,res);
        path.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        vector<vector<int>> res;
        vector<int> path;
        dfs(index,nums,path,res);
        return res;
    }
};