// Last updated: 11/05/2026, 01:32:23
class Solution {
    vector<int> v;
    int find(int x){
        return v[x] == x? x: find(v[x]);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        int n = isConnected.size();
        v.resize(n+1, 0);
        for (int i = 0; i <= n; i++)
            v[i] = i;
        int cnt = n;
        for (int i = 0; i < isConnected.size(); i++){
            for (int j = 0; j < isConnected[0].size(); j++){
                if (isConnected[i][j]){
                    int x = find(i);
                    int y = find(j);
                    if (x != y){
                       v[x] = y;
                        cnt--;
                    }
                }
            }
        }
        // for(int i: v)
            // cout<<i<<" ";
        return cnt;
    }
};