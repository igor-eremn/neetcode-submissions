class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        let map = {};

        for(let i=0; i<nums.length; i++){
            let num = nums[i];
            if(map[num]){
                return true
            } else {
                map[num] = 1;
            }
        }

        return false;
    }
}
