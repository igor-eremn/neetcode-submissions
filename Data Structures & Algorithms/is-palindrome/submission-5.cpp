class Solution {
public:
    bool isPalindrome(string s) {
        // removing all non-letter characters
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !std::isalnum(c);
        }), s.end());

        // converting all letters to lowercase
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        int l = 0;
        int r = s.size() - 1;

        while (l < r){
            if (s[l] != s[r]) {
                return false;
            } else {
                l++;
                r--;
            }
        }

        return true;
    }
};
