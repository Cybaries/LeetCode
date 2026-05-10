// Last updated: 11/05/2026, 01:30:56
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> first(26,0);
        int count = 0;
        for (int i  = 0; i < s.size(); i++){
            first[s[i]-'a']++;
        }
        for (int i  = 0; i < t.size(); i++){
            if (first[t[i]-'a'] == 0){
                count++;
                continue;
            }
            first[t[i]-'a']--;
        }
        for(int x: first){
            count += x;
        }
        return count;
    }
};