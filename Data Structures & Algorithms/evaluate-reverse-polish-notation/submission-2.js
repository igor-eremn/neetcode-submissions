class Solution {
    /**
     * @param {string[]} tokens
     * @return {number}
     */
    evalRPN(tokens) {
        let res = Infinity;
        let s = [];

        const smth = (a, b, op) => {
            console.log(a, b, op);
            let res;
            if (op == "+") res = a + b;
            if (op == "-") res = a - b;
            if (op == "*") res = a * b;
            if (op == "/") res = a / b;
            return res < 0 ? Math.ceil(res) : Math.floor(res);
        }

        const check = (x) => {
            if (x == "+" || x == "-" || x == "*" || x == "/") return false;
            return true;
        }

        for (let i=0; i<tokens.length; i++) {
            if (check(tokens[i])){
                s.push(Number(tokens[i]));
            } else {
                let b = s.pop();
                let a = s.pop();
                s.push(smth(a, b, tokens[i]));
                console.log(s);
            }
        }

        return s[0];
    }
}
