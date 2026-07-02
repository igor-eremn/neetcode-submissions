class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        let s = new Set();
        let res = 0;
        let used = new Set();
        let starters = [];

        for (let i=0; i<nums.length; i++) {
            s.add(nums[i]);
        }

        for (let val of s) {
            if (!s.has(val - 1)) starters.push(val);
        }

        for (let i=0; i<starters.length; i++) {
            let seq = [];
            let found = false;
            let temp = starters[i];
            while (!found) {
                seq.push(temp);
                if (s.has(temp + 1)){
                    temp++;
                } else {
                    found = true;
                }
            }
            res = Math.max(res, seq.length);
        }
        
        return res;
    }
}
