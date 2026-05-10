// Last updated: 11/05/2026, 01:30:30
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            if (grid[i][i] == 0)
                return false;
            if (grid[i][grid.size()-1-i] == 0)
                return false;
            for(int j = 0; j < grid.size(); j++){
                if (j != i && j != grid.size()-i-1 && grid[i][j] != 0){
                    return false;
                }
            }
        }
        return true;
    }
};