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
    }
};
