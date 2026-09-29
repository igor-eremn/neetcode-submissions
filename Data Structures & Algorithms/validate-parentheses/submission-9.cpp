class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m{{')','('},{']','['},{'}','{'}};
        vector<char> st{};

        for (int i=0; i<s.size(); i++) {
            auto t = s[i];
            if (m.find(t) != m.end()){
                if (st.size() == 0){
                    return false;
                } else {
                    auto c = st.back();
                    if (c != m[t]){
                        return false;
                    } else {
                        st.pop_back();
                    }
                }
            } else {
                st.push_back(t);
            }
        }

        if (st.size() > 0) {
            return false;
        }

        return true;
    }
};
