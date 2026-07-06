class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups{};

        for (const string& s : strs)
        {
            vector<int> key_map(26, 0);
            
            for (int k=0; k<s.size(); k++)
            {
                key_map[s[k] - 'a']++;
            }

            string key{};
            for (const auto& num : key_map)
            {
                key += to_string(num) + ":";
            }
            
            groups[key].push_back(s);
        }

        vector<vector<string>> res{};
        res.reserve(groups.size());

        for (auto& [key, value] : groups) {
            res.push_back(std::move(value));
        }

        return res;
    }
};
