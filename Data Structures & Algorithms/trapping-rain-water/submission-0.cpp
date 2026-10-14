class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;  int r = height.size()-1;
        int mL = 0; int mR = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                mL = max(mL, height[l]);
                res += (mL - height[l]);
                l++;
            } else {
                mR = max(mR, height[r]);
                res += (mR - height[r]);
                r--;
            }
        }

        return res; 
    }
};
