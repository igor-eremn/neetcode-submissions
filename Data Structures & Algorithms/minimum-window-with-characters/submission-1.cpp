class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        
        if (t.size() > s.size()) {
            return res;
        }

        unordered_map<char, int> tm{};
        unordered_map<char, int> sm{};

        for (int i=0; i<t.size(); i++) {
            tm[t[i]]++;
        }

        int l = 0; int best_start = 0; int best_len = INT_MAX;
        int matches = 0; int need = tm.size();

        for (int r=0; r<s.size(); r++) {
            auto ch = s[r];
            if (tm.count(ch) && ++sm[ch] == tm[ch]) matches++;

            while (matches == need) {
                if (r - l + 1 < best_len) {
                    best_len = r - l + 1;
                    best_start = l;
                }
                char lc = s[l++];
                if (tm.count(lc) && --sm[lc] < tm[lc]) matches--;
            }
        }

        return best_len == INT_MAX ? "" : s.substr(best_start, best_len);
    }
};
