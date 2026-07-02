class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isValid(s) {
        if (s.length % 2 !== 0) return false;

        let st = [];
        for (let i=0; i<s.length; i++){
            let c = s.charAt(i);
            if (c == '(' || c == '{' || c == '['){
                st.push(c);
            } else {
                if (c == ')') {
                    if (st.pop() !== '(') return false;
                } else if (c == '}') {
                    if (st.pop() !== '{') return false;
                } else {
                    if (st.pop() !== '[') return false;
                }
            }
        }

        if (st.length !== 0) return false;

        return true;
    }
}
