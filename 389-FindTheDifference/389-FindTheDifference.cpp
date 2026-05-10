// Last updated: 11/05/2026, 01:32:44
class Solution {
public:
    char findTheDifference(string s, string t) {
        int co1=0,co0=0;
        for (int i = 0; i < s.size(); i++){
            co0 += s[i];
        }
        for (int i = 0; i < t.size(); i++){
            co1 += t[i];
        }
        return (char)(co1 - co0);
    }
};