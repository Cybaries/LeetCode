// Last updated: 11/05/2026, 01:30:17
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (string i: details){
            if (i[11] == '6' && i[12] > '0') cnt++;
            else if (i[11] > '6') cnt++;
        }
        return cnt;
    }
};