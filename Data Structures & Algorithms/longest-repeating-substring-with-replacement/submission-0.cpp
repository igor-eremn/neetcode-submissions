class Solution {
public:
    int characterReplacement(string s, int k) {
        // window_length - most_repeating_char <= k

        int l = 0; int res = 0; int mr = 0;
        unordered_map<char, int> m{};

        for (int i=0; i<s.size(); i++) {
            auto c = s[i];
            m[c]++;
            mr = max(mr, m[c]);

            while ((i - l + 1) - mr > k) {
                m[s[l]]--;
                l++;
            }

            res = max(res, i-l+1);
        }

        return res;
    }
};
