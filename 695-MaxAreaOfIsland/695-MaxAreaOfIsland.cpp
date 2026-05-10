// Last updated: 11/05/2026, 01:32:18
class Solution {
    int dfs(vector<vector<int>>& arr, int i, int j){
        if (0 <= i && i < arr.size() && j >= 0 && j < arr[i].size() && arr[i][j] == 1){
            arr[i][j] = 0;
            return 1 + dfs(arr, i+1, j) + dfs(arr, i-1, j) +  dfs(arr, i, j+1) + dfs(arr, i, j-1);
        }
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++){
            for (int j = 0; j < arr[i].size(); j++){
                if (arr[i][j] == 1){
                    cnt = max(cnt, dfs(arr, i, j));
                }
            }
        }
        return cnt;
    }
};