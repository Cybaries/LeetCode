class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        vector<int> v(1,1);
        triangle.push_back(v);
        if (numRows == 1)
            return triangle;
        v.resize(2,1);
        triangle.push_back(v);
        for (int i = 2; i < numRows; i++){
            vector<int> next(i+1, 1);
            for (int j = 1; j < i; j++){
                next[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            triangle.push_back(next);
        }
        return triangle;
    }
};