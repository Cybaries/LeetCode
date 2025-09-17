class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int minTime = 201;
        for (vector<int>& i: tasks){
            int temp = i[0]+i[1];
            minTime = min(temp, minTime);
        }
        return minTime;
    }
};