class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = 1000000;

        for (int i=0; i<prices.size(); i++) {
            buy = min(buy, prices[i]);
            res = max(res, prices[i] - buy);
        }

        return res;
    }
};
