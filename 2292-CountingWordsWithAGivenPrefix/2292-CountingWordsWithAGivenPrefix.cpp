// Last updated: 11/05/2026, 01:31:00
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string x: words){
            if (x.size() < pref.size())
                continue;
            if (x.substr(0,pref.size()) == pref)
                count++;
        }
        return count;
    }
};