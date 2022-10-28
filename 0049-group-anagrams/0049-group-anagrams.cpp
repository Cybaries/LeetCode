class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> mp;
        for (string s: strs){
            vector<char> v;
            for(char c: s)
                v.push_back(c);
            sort(v.begin(), v.end());
            string y ;
            for (char x: v)
                y += x;
            if (mp.find(y) == mp.end())
                mp.insert({y, {s}});
            else
                mp[y].push_back(s);
        }
        for(auto p: mp){
            res.push_back(p.second);
        }
        return res;
    }
};