class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> groups{};

        vector<vector<int>> freq{nums.size() + 1};

        for (int i=0; i<nums.size(); i++)
        {
            groups[nums[i]]++;
        }

        for (const auto& [key,value] : groups)
        {
            freq[value].push_back(key);
        }

        vector<int> res{};
        res.reserve(k);
        for (int i=freq.size()-1; i>=0; i--)
        {
            const auto& check = freq[i];
            if (check.size() > 0)
            {
                for (int m=0; m<check.size(); m++)
                {
                    res.push_back(check[m]);
                    if (res.size() == k)
                    {
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
