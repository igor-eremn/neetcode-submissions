class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        let m = new Map();

        for (let i=0; i<nums.length; i++) {
            m.set(nums[i], i);
        }

        let res = [];
        for(let i=0; i<nums.length; i++){
            let r = target - nums[i];
            if (m.has(r) && m.get(r) !== i){
                res.push(m.get(r));
                res.push(i);
                break;
            }
        }

        return res;
    }
}
