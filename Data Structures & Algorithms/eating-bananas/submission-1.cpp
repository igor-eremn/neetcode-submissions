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
                temp += (piles[i] - 1) / m + 1 ;
            }

            if (temp <= h) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return res;
    }
};
