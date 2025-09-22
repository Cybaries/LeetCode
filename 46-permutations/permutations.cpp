class Solution {
public:
    void dfs(int index, vector<int>& temp, vector<int>& nums, vector<vector<int>>& res){
        if (index == nums.size()){
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue; // Skip element if already in temp
            //Include element
            temp.push_back(nums[i]);
            dfs(index+1, temp, nums, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0, temp, nums, res);
        return res;
    }
};