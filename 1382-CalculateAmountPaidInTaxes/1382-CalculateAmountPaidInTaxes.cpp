// Last updated: 11/05/2026, 01:31:48
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double cost = 0;
        cost += min(brackets[0][0], income) * brackets[0][1]/100.0;
        if (!(income <= brackets[0][0]))
        for (int i = 1; i < brackets.size(); i++){
            cost += (min(brackets[i][0], income) - brackets[i-1][0]) * brackets[i][1]/100.0;
            cout<<cost<<endl;
            if (income <= brackets[i][0])
                break;
        }
        return min(cost, (double)income);
    }
};