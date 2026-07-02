class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        let map = new Map();
        let res = [];
        for(let i=0; i<strs.length; i++){
            let str = strs[i];
            str = str.split('').sort().join('');
            if (!map.has(str)) {
                map.set(str, [i]);
            } else {
                map.get(str).push(i);
            }
        }
        
        for(let group of map){
            let indexes = [...group[1]];
            let temp = [];
            for(let i=0; i<indexes.length; i++){
                temp.push(strs[indexes[i]]);
            }
            res.push(temp);
        }
        return res;
    }
}
