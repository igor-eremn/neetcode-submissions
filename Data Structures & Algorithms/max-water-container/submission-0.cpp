class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;

        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            int height = heights[l] > heights[r] ? heights[r] : heights[l];
            int width = r - l;
            res = max(res, height * width);

            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }

        return res;
    }
};
