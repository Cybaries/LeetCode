class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        for (char c: s) v[c-97]++;
        for (char c:t) v[c-97]--;
        for (int i: v){
            if (i) return false;
        }
        return true;
    }
};