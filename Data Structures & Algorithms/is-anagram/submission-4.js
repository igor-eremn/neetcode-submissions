class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if (s.length !== t.length) return false;
        let m = new Map();
        for(let i=0; i<s.length; i++){
            m.set(s.charAt(i), (m.get(s.charAt(i)) ?? 0) + 1);
        }

        for(let i=0; i<t.length; i++){
            let char = t.charAt(i);
            if (m.get(char)){
                if (m.get(char) === 0){
                    return false;
                } else {
                    m.set(char, m.get(char) - 1);
                }
            } else {
                return false;
            }
        }

        for(let val of m.values()){
            if(val > 0){
                return false;
            }
        }
        return true;
    }
}
