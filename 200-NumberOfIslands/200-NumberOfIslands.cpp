// Last updated: 11/05/2026, 01:33:14
class Solution {
    void dfs(vector<vector<char>>& arr, int i, int j){
       if (0 <= i && i < arr.size() && 0 <= j && j < arr[i].size() && arr[i][j] == '1') {
            arr[i][j] = '0';
            dfs(arr, i - 1, j);
            dfs(arr, i, j - 1);
            dfs(arr, i + 1, j);
            dfs(arr, i, j + 1);
        }
    }
public:
    int numIslands(vector<vector<char>>& arr) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[0].size(); j++){
                if(arr[i][j] == '1'){
                    cnt++;
                    dfs(arr,i,j);
                }
            }
        }
        return cnt;
    }
};