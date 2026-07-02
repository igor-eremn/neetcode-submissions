class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {
        s = s.replace(/[^a-z0-9]/gi, '').toLowerCase();
        let toCheck = s.split('');
        let left = 0; 
        let right = s.length-1;
        while(left < right){
            if(toCheck[left] !== toCheck[right]){
                console.log(toCheck[left], toCheck[right]);
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}
