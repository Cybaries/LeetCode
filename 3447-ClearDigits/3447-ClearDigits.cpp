// Last updated: 11/05/2026, 01:30:15
class Solution {
public:
    string clearDigits(string s) {
        if (isdigit(s[0])) s.erase(0);
        string result = "";
        for (int i = 0; i < s.size(); i++){
            if (isdigit(s[i])){
               result.erase(result.size()-1);
            }
            else{
                result+= s[i];
            }
        }
        return result;
    }
};