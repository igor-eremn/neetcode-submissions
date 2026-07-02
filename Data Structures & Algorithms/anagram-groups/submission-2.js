class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        let map = {};
        for(let i=0; i<strs.length; i++){
            let key = new Array(26).fill(0);
            let s = strs[i];

            for(let j=0; j<s.length; j++){
                let temp = s.charAt(j).charCodeAt(0) - 'a'.charCodeAt(0);
                key[temp]++;
            }

            if(map[key]){
                map[key].push(strs[i])
            } else {
                map[key] = [strs[i]];
            }
        }

        let res = []
        for(const key in map){
            res.push([...map[key]]);
        }
        return res;
    }
}
