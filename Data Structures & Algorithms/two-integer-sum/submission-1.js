class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        let map = new Map();
        for(let i=0; i<nums.length; i++){
            let x = target - nums[i];
            let temp = map.get(x);
            let check = map.has(x);
            if(check){
                return [temp, i];
            }
            map.set(nums[i], i);
        }
        return [-1,-1];
    }
}
