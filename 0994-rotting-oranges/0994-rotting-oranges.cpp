class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<vector<int>> q;
        vector<vector<int>> v {{1,0},{-1,0},{0,1},{0,-1}};
        int rows = grid.size();
        int cols = grid[0].size();
        int healthy = 0;
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    healthy++;
            }
        }
        int minutes = 0;
        while(healthy>0 && !q.empty()){
            minutes++;
            int lim = q.size();
            for (int i = 0; i < lim; i++){
                for (auto j: v){
                    vector<int> k = q.front();
                    if(k[0]+j[0] < 0 || k[0]+j[0] >= rows || k[1]+j[1] < 0 || k[1]+j[1] >= cols)
                        continue;
                    if(grid[k[0]+j[0]][k[1]+j[1]] ==2 || grid[k[0]+j[0]][k[1]+j[1]] == 0)
                        continue;
                    // cout<<k[0]<<" "<<j[0]<<" "<<k[1]<<" "<<j[1]<<endl;
                    healthy--;
                    grid[k[0]+j[0]][k[1]+j[1]] = 2;
                    q.push({k[0]+j[0], k[1]+j[1]});
                }
                q.pop();
            }
        }
        return healthy == 0? minutes:-1;
    }
};