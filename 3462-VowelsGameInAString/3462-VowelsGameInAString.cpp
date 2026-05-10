// Last updated: 11/05/2026, 01:30:13
class Solution {
public:
    bool doesAliceWin(string s) {
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                return true;
            }
        }
        return false;
        
    }
};