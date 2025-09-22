class Solution {
public:
    void dfs(int l, int r, int n, string s, vector<string>& res){
        if (s.size() == n*2){
            res.push_back(s);
            return;
        }
        if (l < n){
            dfs(l+1, r, n, s+'(', res);
        }
        if (r < l){
            dfs(l, r+1, n, s+')', res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, n, "", res);
        return res;
    }
};