// Last updated: 11/05/2026, 01:32:16
class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<bool>>& visit, int x){
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) return;
        // cout<< sr <<" "<<sc<<" "<<x<<
        if (visit[sr][sc] || image[sr][sc] != x) return;
        visit[sr][sc] = true;
        image[sr][sc] = color;
        dfs(image, sr+1, sc, color, visit,x);
        dfs(image, sr, sc-1, color, visit,x);
        dfs(image, sr, sc+1, color, visit,x);
        dfs(image, sr-1, sc, color, visit,x);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x = image[sr][sc];
        vector<vector<bool>> visit(image.size(), vector<bool> (image[0].size()));
        dfs(image, sr, sc, color, visit,x);
        return image;
    }
};