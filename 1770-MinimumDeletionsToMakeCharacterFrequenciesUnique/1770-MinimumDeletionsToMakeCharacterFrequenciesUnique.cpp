// Last updated: 11/05/2026, 01:31:40
class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        for (auto x: s)
            v[x-97]++;
        sort(v.begin(), v.end());
        int cnt = 0;
        for (int i = 24; i >= 0; i--){
            if (v[i] == 0) break;
            if (v[i] >= v[i+1]){
                int pre = v[i];
                v[i] = max(0, v[i+1]-1);
                cnt += pre - v[i];
            }
        }
        return cnt;
    }
};