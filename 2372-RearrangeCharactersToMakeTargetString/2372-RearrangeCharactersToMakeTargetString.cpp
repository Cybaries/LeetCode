// Last updated: 11/05/2026, 01:30:42
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
       vector<int> alph(26);
        vector<int> beta(26);
        for (auto i: s){
            alph[i-97]++;
        }
        int mn = INT_MAX;
        for (auto i: target){
            beta[i-97]++;
        }
        for (auto i: target){
            mn = min(alph[i-97]/beta[i-97], mn);
        }
        return mn;
    }
};