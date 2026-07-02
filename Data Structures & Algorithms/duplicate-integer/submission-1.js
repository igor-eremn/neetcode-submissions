class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        let set = new Set();
        for(let i in nums){
            if(set.has(nums[i])) return true;
            set.add(nums[i]);
        }
        return false;
    }
}
