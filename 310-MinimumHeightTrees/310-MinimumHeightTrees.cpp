// Last updated: 11/05/2026, 01:32:49
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n);
        vector<int> res;
        vector<vector<int>> adj(n);
        if (n == 1){
            res.push_back(0);
            return res;
        }
        for (auto i : edges)
        {
            deg[i[0]]++;
            deg[i[1]]++;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (deg[i] == 1)
                q.push(i);
        }
        while(n > 2){
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                for (int j = 0; j < adj[cur].size(); j++){
                    deg[adj[cur][j]]--;
                    if (deg[adj[cur][j]] == 1)
                        q.push(adj[cur][j]);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};