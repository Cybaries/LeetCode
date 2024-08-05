class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int result = 0;
        for (int i: prices){
            if (minVal > i) minVal = i;
            result = max(i-minVal, result);
        }
        return result;
    }
};