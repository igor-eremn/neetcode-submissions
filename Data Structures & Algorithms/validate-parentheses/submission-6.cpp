class Solution {
public:
    bool isValid(string s) {
        string res{};
        for(int i=0; i<s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                res += s[i];
                cout << res << '\n';
            } else {
                if (res.size() == 0){
                    return false;
                } else if (s[i] == ')' && res[res.size()-1] != '('){
                    return false;
                } else if (s[i] == '}' && res[res.size()-1] != '{'){
                    return false;
                } else if (s[i] == ']' && res[res.size()-1] != '['){
                    return false;
                } else {
                    res.pop_back();
                }
            }
        }
        cout << res;

        return res.size() == 0;
    }
};
