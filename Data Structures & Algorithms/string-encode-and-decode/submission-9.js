class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        let res = "";
        for (let i=0; i<strs.length; i++) {
            res += "" + strs[i].length + "#" + strs[i];
        }
        return res;
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        let res = [];
        console.log(str);
        for (let i=0; i<str.length; i++) {
            let sizeS = "";
            while (str.charAt(i) !== "#"){
                sizeS += str.charAt(i);
                i++;
            }
            let size = Number(sizeS);

            let temp = "";
            for (let j=i+1; j<i+1+size; j++) {
                temp += str.charAt(j);
            }
            res.push(temp);
            i = i + size;
        }
        return res;
    }
}
