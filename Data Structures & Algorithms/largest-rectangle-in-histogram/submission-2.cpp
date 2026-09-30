class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> s{};
        int res = 0;

        // monotonic increasing stack, stack logic: 
        // we keep elements for which we could not find the lower boundary
        // when we find height that is lower than s.back(), we process
        // this stack (start popping elements from the back till we find
        // element that is smaller than current one, while calculating their 
        // rectangle value)
        for (int i=0; i<heights.size(); i++) {
            while (!s.empty() && heights[s.back()] > heights[i]) {
                int h = heights[s.back()];
                s.pop_back();

                int left = s.empty() ? -1 : s.back();
                int width = i - left - 1;

                res = max(res, h * width);
            }
            s.push_back(i);
        }

        // process remaining elements on the stack
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
