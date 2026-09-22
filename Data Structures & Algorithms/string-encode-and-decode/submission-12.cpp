class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (int i=0; i<strs.size(); i++){
            res += to_string(strs[i].size()) + "#";
            res += strs[i];
        }
        cout << res << "\n";
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string num;
        for (int i=0; i<s.length(); i++){
            if (s[i] != '#'){
                num += s[i];
            } else {
                i++;
                int len = stoi(num);
                string temp = s.substr(i, stoi(num));
                res.push_back(temp);
                i += len - 1;
                num = "";
            }
        }

        return res;
    }
};
