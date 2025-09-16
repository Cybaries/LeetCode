class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int startIndex = 0;
        for (int i = 0; i < prices.size(); i++){
            if (prices[i] < prices[startIndex]) startIndex = i;
            maxProfit = max(maxProfit, prices[i] - prices[startIndex]);
        }
        return maxProfit;
    }
};