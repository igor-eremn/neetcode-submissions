class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m{};
        int res = 0;
        int l = 0;

        for (int i=0; i<s.size(); i++) {
            auto ch = s[i];
            if (m.find(ch) != m.end() && m[ch] == 1) {
                while (m[ch] == 1) {
                    m[s[l]]--;
                    l++;
                }
            }
            res = max(res, i - l + 1);
            m[ch]++;
        }

        return res;

        // possible better solution is to store all 128 characters in the map
        // keep track of the last occurence and when we find 
        // duplicate, we jump to the last place that we saw that character (+1) so we dont even need while loop to clear duplicates
    }
};
