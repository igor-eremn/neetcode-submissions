class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> s{};
        unordered_set<string> o{"+", "-", "*", "/"};

        for (int i=0; i<tokens.size(); i++) {
            string t = tokens[i];
            if (o.contains(t)){
                auto a = stoi(s.back()); s.pop_back();
                auto b = stoi(s.back()); s.pop_back();
                if (t == "+"){
                    a = a + b;
                    s.push_back(to_string(a));
                } else if (t == "-"){
                    b = b - a;
                    s.push_back(to_string(b));
                } else if (t == "*"){
                    a = a * b;
                    s.push_back(to_string(a));
                } else {
                    b = b / a;
                    s.push_back(to_string(b));
                }
            } else {
                s.push_back(t);
            }
        }


        return stoi(s.back());
    }
};
