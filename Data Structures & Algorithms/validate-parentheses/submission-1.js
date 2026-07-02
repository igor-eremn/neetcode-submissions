class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s) {
        let stack = [];
        for(let i=0; i<s.length; i++){
            let char = s.charAt(i);
            let toCheck = stack[stack.length-1];
            if(char === '(' || char === '{' || char === '['){
                stack.push(char);
            } else {
                let temp = toCheck + char;
                if (temp === '()' || temp === '{}' || temp === '[]'){
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        if(stack.length > 0) return false;
        return true;
    }
}
