class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m{};

        if (s.size() != t.size()) return false;

        for (int i=0; i<s.size(); i++) {
            auto c = s[i];
            if (m.find(c) != m.end()){
                m[c]++;
            } else {
                m.insert({c, 1});
            }
        }

        for (int i=0; i<t.size(); i++){
            auto c = t[i];
            if (m.find(c) != m.end()){
                if (m[c] == 0){
                    return false;
                } else {
                    m[c]--;
                }
            } else {
                return false;
            }
        }

        for (const auto& [key, value] : m) {
            if (value != 0){
                return false;
            }
        }

        return true;
    }
};
