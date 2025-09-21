class Solution {
public:
    void dfs (int index, vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& res){
        if (target == 0){
            res.push_back(path);
            return;
        }
        if (target < 0 || index == candidates.size()) return;
        //Include element
        path.push_back(candidates[index]);
        dfs (index + 1, candidates, target - candidates[index], path, res);
        path.pop_back();
        //Exclude element
        while (index < candidates.size()-1 && candidates[index] == candidates[index+1]) index++;
        dfs(index+1, candidates, target, path, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        dfs(0, candidates, target, path, res);
        return res;
    }
};
