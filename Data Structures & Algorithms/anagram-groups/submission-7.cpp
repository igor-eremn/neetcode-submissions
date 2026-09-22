class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m{};
        vector<vector<string>> res{};

        for(int i=0; i<strs.size(); i++) {
            vector<int> a(26,0);
            for (int j=0; j<strs[i].size(); j++){
                a[strs[i][j] - 'a']++;
            }
            (m[a]).push_back(strs[i]);
        }

        for (const auto& [key,value] : m){
            res.push_back(value);
        }

        return res;
    }
};
