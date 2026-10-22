class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0; 
        int r = nums.size() - 1;
        int res = INT_MAX;

        // the idea is:
        // 1. we check if the vector is already sorted (first if)
        // if it is, then grab left value
        // 2. if it is not, then we check middle value and left value
        // if m > l, then left part is sorted and we need to check on the right
        // if m < l, then min is on the left side
        while (l <= r) {
            if (nums[l] <= nums[r]) {
                res = min(res,nums[l]);
                break;
            }

            int m = l + (r - l) / 2;
            res = min(res, nums[m]);

            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
};
