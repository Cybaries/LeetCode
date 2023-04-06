class Solution {
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 0){
                    res += dfs(grid, i, j) ? 1 : 0;
                }
            }
        }
        return res;
    }
    bool dfs(vector<vector<int>>& g, int i, int j){
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()){
            return false;
        }
        if (g[i][j] == 1){
            return true;
        }
        g[i][j] = 1;
        bool d1 = true;
        d1 &= dfs(g, i+1, j);
        d1 &= dfs(g, i, j+1);
        d1 &= dfs(g, i-1, j);
        d1 &= dfs(g, i, j-1);
        return d1;
    }
};