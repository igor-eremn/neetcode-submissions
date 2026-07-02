class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        let map = {};
        for(let i=0; i<nums.length; i++){
            map[target-nums[i]] = i;
        }

        let res = [];
        for(let i=0; i<nums.length; i++){
            if(map[nums[i]] && map[nums[i]] !== i){
                if(i < map[nums[i]]){
                    return [i, map[nums[i]]];
                } else {
                    return [map[nums[i]], i];
                }
            }
        }

        return res;
    }
}
