class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        let m = new Map();
        for(let i=0; i<strs.length; i++){
            let t = [...strs[i]].sort().join("");
            if (!m.has(t)){
                m.set(t, []);
            } 
            m.set(t, [...m.get(t), strs[i]]);
        }

        let res = [];
        for (let val of m.values()) {
            res.push(val);
        }

        return res;
    }
}
