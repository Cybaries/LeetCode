// Last updated: 11/05/2026, 01:31:32
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n > original.size() || original.size() > m*n)
            return {};
        int start=0;
        vector<vector<int>> ans;
        for (int i= 0; i< m; i++ ){
            vector<int> v;
            for (int j=0; j< n; j++){
                v.push_back(original[start++]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};