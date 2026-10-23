class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) { // found target
                res = m;
                break;
            } else if (nums[l] < nums[r]) { // checking sorted portion
                if (nums[m] > target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (nums[l] <= nums[m]) { // left side is sorted
                if (target > nums[m]){
                    l = m + 1;
                } else if (target < nums[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (target >= nums[l] || target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }


        }

        return res; 
    }
};
