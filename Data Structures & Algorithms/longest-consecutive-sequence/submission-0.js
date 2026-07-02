class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        let s = new Set();
        let res = 0;
        let used = new Set();

        for (let i=0; i<nums.length; i++) {
            s.add(nums[i]);
        }

        for (let val of s) {
            let found = false;
            let temp = val;
            let count = 0;

            while (!found) {
                if (s.has(temp - 1)){
                    temp--;
                } else {
                    found = true;
                }
            }

            found = false;
            while (!found) {
                count++;
                if (s.has(temp + 1)){
                    temp++;
                } else {
                    found = true;
                }
            }
            res = Math.max(res, count);
        }
        
        return res;
    }
}
