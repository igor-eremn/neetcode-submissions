class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;

        for (int i=0; i<piles.size(); i++) {
            max = max >= piles[i] ? max : piles[i];
        }

        int res = max;
        int l = 1;
        int r = res;

        while (l <= r) {
            int m = l + (r - l) / 2;

            int temp = 0;
            for (int i=0; i<piles.size(); i++) {
                temp += ((piles[i] + m - 1) / m);
            }

            if (temp <= h) {
                res = min(res, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return res;
    }
};
