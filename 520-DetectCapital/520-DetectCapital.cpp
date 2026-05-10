// Last updated: 11/05/2026, 01:32:31
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word[0] <= 90){
            if (word[1] > 90){
                for (int i = 2; i < word.size(); i++){
                    if (word[i] <= 90)
                        return false;
                }
            }
            else{
                for (int i = 2; i < word.size(); i++){
                    if (word[i] > 90)
                        return false;
                }
            }
        }
        else{
            for (int i = 1; i < word.size(); i++){
                    if (word[i] <= 90)
                        return false;
                }
        }
        return true;
    }
};