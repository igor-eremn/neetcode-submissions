class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        let temp_s = (s.split('')).sort();
        let temp_t = (t.split('')).sort();
        if(temp_s.length != temp_t.length){
            return false;
        }else{
            for(let i=0; i<temp_s.length; i++){
                if(temp_s[i] != temp_t[i]){
                    return false;
                }
            }
        }
        return true;
    }
}
