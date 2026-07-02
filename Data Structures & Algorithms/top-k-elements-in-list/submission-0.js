class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        let m = new Map();
        for(let i=0; i<nums.length; i++){
            if(m.has(nums[i])){
                m.set(nums[i], m.get(nums[i])+1);
            } else {
                m.set(nums[i], 1);
            } 
        }
        console.log(m);

        let buckets = new Array(nums.length + 1);
        for (let [key, value] of m.entries()) {
            if (buckets[value]){
                buckets[value] = [...buckets[value], key];
            } else {
                buckets[value] = [key];
            }
        }
        console.log(buckets);

        let res = [];
        for(let i=buckets.length - 1; i>=0; i--){
            if(buckets[i] !== null && buckets[i] !== undefined){
                for(let j=0; j<buckets[i].length; j++){
                    res.push(buckets[i][j]);
                    if (res.length == k) break;
                }
            }
            if (res.length == k) break;
        }
        
        return res;
    }
}
