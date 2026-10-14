class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = 101;
        int sell = 0;

        for (int i=0; i<prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
                sell = prices[i];
            } else if (prices[i] > sell) {
                sell = prices[i];
            }
            res = max(res, sell - buy);
        }

        return res;
    }
};
