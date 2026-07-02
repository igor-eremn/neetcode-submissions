class Solution {
    /**
     * @param {number[]} numbers
     * @param {number} target
     * @return {number[]}
     */
    twoSum(numbers, target) {
        let start = 0;
        let end = numbers.length - 1;
        let res = [];

        while (start < end) {
            let temp = numbers[start] + numbers[end];
            if (temp == target){
                res.push(start + 1);
                res.push(end + 1);
                break;
            } else if (temp < target) {
                start++;
            } else {
                end--;
            }
        }

        return res;
    }
}
