class Solution {
    /**
     * @param {string} s
     * @return {boolean}
     */
    isPalindrome(s) {
        s = s.replace(/[^a-zA-Z0-9]/g, '').toLowerCase();
        let start = 0;
        let end = s.length - 1;
        while (start <= end) {
            if (s.charAt(start) !== s.charAt(end)){
                return false;
            } else {
                start++;
                end--;
            }
        }

        return true;
    }
}
