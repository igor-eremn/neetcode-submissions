class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> s{};
        int res = 0;

        for (int i=0; i<heights.size(); i++) {
            if (s.size() == 0) {
                s.push_back(i);
            } else {
                if (heights[s.back()] <= heights[i]) {
                    s.push_back(i);
                } else {
                    while (s.size() > 0 && heights[s.back()] > heights[i]) {
                        int h = heights[s.back()];
                        s.pop_back();

                        int left = s.empty() ? -1 : s.back();
                        int width = i - left - 1;

                        res = max(res, h * width);
                    }
                    s.push_back(i);
                }
            }
        }

        while (!s.empty()) {
            int h = heights[s.back()];
            s.pop_back();

            int left = s.empty() ? -1 : s.back();
            int width = heights.size() - left - 1;

            res = max(res, h * width);
        }

        return res;
    }
};
