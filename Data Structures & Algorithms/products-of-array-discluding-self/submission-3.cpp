class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prs(nums.size());
        vector<int> pss(nums.size());
        vector<int> res(nums.size());

        for (int i=0; i<nums.size(); i++) {
            if (i == 0){
                prs[i] = nums[i];
            } else {
                prs[i] = prs[i-1] * nums[i];
            }
        }


        for (int i=nums.size()-1; i>=0; i--) {
            if (i == nums.size() - 1){
                pss[i] = nums[i];
            } else {
                pss[i] = nums[i] * pss[i+1];
            }
        }

        for (int i=0; i<nums.size(); i++) {
            if (i == 0) {
                res[i] = pss[i+1];
            } else if (i == nums.size() - 1) {
                res[i] = prs[i-1];
            } else {
                res[i] = prs[i-1] * pss[i+1];
            }
        }

        return res;
    }
};
