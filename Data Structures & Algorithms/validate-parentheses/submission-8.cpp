class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m{{'}','{'}, {']','['}, {')','('}};
        vector<char> st{};

        for (char c : s){
            if (m[c]){
                if(st.size() == 0 || m[c] != st.back()) return false;
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }

        return st.size() == 0;
    }
};
