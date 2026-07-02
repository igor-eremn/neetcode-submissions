class Solution {
    /**
     * @param {number[]} temperatures
     * @return {number[]}
     */
    dailyTemperatures(temperatures) {
        let res = new Array(temperatures.length).fill(0);
        let stack = [];

        for (let i=0; i<temperatures.length; i++) {
            if (stack.length == 0 || stack[stack.length - 1][0] >= temperatures[i]){
                stack.push([temperatures[i], i]);
            } else {
                while (stack.length !== 0 && (stack[stack.length - 1][0] ?? 0) < temperatures[i]) {
                    console.log(i, temperatures[i], stack, res);
                    let idx = stack[stack.length - 1][1];
                    res[idx] = i - idx;
                    stack.pop();
                }
                stack.push([temperatures[i], i]);
            }
        }

        return res;
    }
}
