class Solution {
    int rows, cols;
    void dfs(vector<vector<char>>& arr, int i, int j){
        // cout<<i <<" "<<j<<endl;
        if (i < 0 || j < 0 || i >= rows || j >= cols)
            return;
        if (arr[i][j] != 'O')
            return;
arr[i][j] = 'y';
        dfs(arr, i+1, j);
        dfs(arr, i-1, j);
        dfs(arr, i, j+1);
        dfs(arr, i, j-1);
    }
public:
    void solve(vector<vector<char>>& arr) {
        if (arr.empty())
            return;
        rows = arr.size();
        cols = arr[0].size();
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++)
                if (i == 0 || j == 0 || i == rows-1 || j == cols-1)
                    dfs(arr, i, j);
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                // cout<<arr[i][j]<<" ";
                if (arr[i][j] == 'y')
                    arr[i][j] = 'O';
                else if (arr[i][j] == 'O')
                    arr[i][j] = 'X';
            }
            // cout<<endl;
        }
    }
};