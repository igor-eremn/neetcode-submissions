class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    productExceptSelf(nums) {
        let prs = new Array(nums.length);
        let pss = new Array(nums.length);

        for (let i=0; i<nums.length; i++) {
            prs[i] = (prs[i-1] ?? 1) * nums[i];
        }

        for (let i=nums.length - 1; i>=0; i--) {
            pss[i] = (pss[i+1] ?? 1) * nums[i];
        }

        let res = [];
        for (let i=0; i<nums.length; i++) {
            res.push((prs[i-1] ?? 1) * (pss[i+1] ?? 1));
        }

        return res;
    }
}
