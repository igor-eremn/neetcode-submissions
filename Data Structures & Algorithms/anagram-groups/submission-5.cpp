class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map{};
        vector<vector<string>> res{};

        // static_cast<int>

        for (int i=0; i<strs.size(); i++)
        {
            vector<int> key_map{};
            for(int j=0; j<26; j++)
            {
                key_map.push_back(0);
            }
            
            for (int k=0; k<strs[i].size(); k++)
            {
                key_map[static_cast<int> (strs[i][k]) - 97]++;
            }

            string key{};
            for (const auto& num : key_map)
            {
                key += to_string(num) + ":";
            }
            
            map[key].push_back(strs[i]);
        }

        for (const auto& [key,value] : map)
        {
            vector<string> entry{};
            for(int i=0; i<value.size(); i++)
            {
                entry.push_back(value[i]);
            }
            res.push_back(entry);
        }

        return res;
    }
};
