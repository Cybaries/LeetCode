// Last updated: 11/05/2026, 01:30:29
class Solution {
public:
    int countAsterisks(string s) {
        int sig = 1;
        int cnt = 0;
        for (char i: s){
            if (i == '|')
                sig ^= 1;
            if (sig && i == '*')
                cnt++;
        }
        return cnt;
    }
};