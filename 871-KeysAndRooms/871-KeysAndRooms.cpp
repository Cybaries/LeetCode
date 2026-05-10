// Last updated: 11/05/2026, 01:32:12
class Solution {
    void dfs(int index, vector<vector<int>>& rooms, vector<bool>& visit){
        bool x ;
        if (visit[index]) return;
        visit[index] = true;
        // cout<<index<<" ";
        for (int i = 0; i < rooms[index].size(); i++){
            dfs(rooms[index][i], rooms, visit);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visit(rooms.size());
        dfs(0, rooms, visit);
        for (bool x: visit){
            // cout<< x<<" ";
            if (!x) return false;
        }
        return true;
    }
};