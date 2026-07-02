class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number}
     */
    search(nums, target) {
        const check = (start, end) => {
            if (start > end) return -1;
            let middle = start + Math.floor((end - start) / 2);
            if (nums[middle] === target) return middle;
            if (nums[middle] > target) return check(start, middle - 1);
            if (nums[middle] < target) return check(middle + 1, end);
        }

        return check(0, nums.length-1);
    }
}
