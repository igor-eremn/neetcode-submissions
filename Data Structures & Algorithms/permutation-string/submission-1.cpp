class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // possible improvement is to uses 'matches' not to do a == b every time
        // compares how many elements in the array match, starting from 0 and returns true if matches = 26 (vectors match)
        vector<int> a(26), b(26);

        if (s1.size() > s2.size()){
            return false;
        }

        for (int i=0; i<s1.size(); i++) {
            auto c = s1[i];
            a[c - 'a']++;
        }

        int i = 0;
        for (; i<s1.size(); i++){
            auto c = s2[i];
            b[c - 'a']++;
        }

        if (a == b) return true;

        while (i < s2.size()) {
            b[s2[i - s1.size()] - 'a']--;
            b[s2[i] - 'a']++;
            if (a == b) {
                return true;
            }
            i++;
        }

        return false;
    }
};
