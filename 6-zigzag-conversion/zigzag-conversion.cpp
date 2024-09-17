class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        int i = 0;
        while(i < s.size()){
            int j = 0, k;
            for (k = 0; k < numRows && i< s.size(); k++)
            {
                v[k].push_back(s[i]);
                // j++;
                i++;
            }
            k--;
            for (int l = 1; l < numRows - 1 && i< s.size(); l++)
            {
                k--;
                v[k].push_back(s[i]);
                i++;
            }
        }
        string str = "";
        for (i = 0; i < numRows; i++){
            // cout << i << endl;
            for (auto x : v[i])
                str += x;
            // cout << endl;
        }
        return str;
    }
};