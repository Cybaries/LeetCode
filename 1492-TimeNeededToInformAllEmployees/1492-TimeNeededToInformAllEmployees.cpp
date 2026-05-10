// Last updated: 11/05/2026, 01:31:45
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        
        for(int i=0; i<n; ++i) {
            ans = max(ans, dfs(i, manager, informTime));
        }
        return ans;
    }
    
    int dfs(int i, vector<int>& manager, vector<int>& informTime) {
        if(manager[i] != -1) {
            informTime[i] += dfs(manager[i], manager, informTime);
            manager[i] = -1;
        }
        return informTime[i];
    }
};