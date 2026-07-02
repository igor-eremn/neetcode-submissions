class Solution {
    /**
     * @param {number[]} prices
     * @return {number}
     */
    maxProfit(prices) {
        let buy = prices[0];
        let profit = 0;

        for(let i=1; i<prices.length; i++){
            profit = Math.max(profit, prices[i] - buy);
            buy = Math.min(buy, prices[i]);
        }

        return profit;
    }
}
