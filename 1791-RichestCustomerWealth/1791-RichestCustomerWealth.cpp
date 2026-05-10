// Last updated: 11/05/2026, 01:31:36
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi= 0;
        for (int i = 0; i < accounts.size(); i++){
            maxi = max(maxi, accumulate(accounts[i].begin(), accounts[i].end(),0));
        }
        return maxi;
    }
};