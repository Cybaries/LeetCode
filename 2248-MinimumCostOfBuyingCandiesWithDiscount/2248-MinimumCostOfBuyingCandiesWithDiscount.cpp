// Last updated: 11/05/2026, 01:31:21
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int costs = 0, counter = 0, i=cost.size()-1;
        while(i>=0){
            // cout << counter<< endl;
            if (counter < 2){
                // cout << cost[i] << endl;
                costs += cost[i];
                counter++;
            }
            else{
                counter = 0;
                // i--;
            }
            i--;
        }
        return costs;
    }
};