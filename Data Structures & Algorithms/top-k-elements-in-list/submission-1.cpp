class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> groups{};

        vector<vector<int>> freq{nums.size() + 1};
        for (int i=0; i<freq.size(); i++)
        {
            vector<int> init{};
            freq[i] = init;
        }

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
            auto check = freq[i];
            if (check.size() > 0)
            {
                for (int m=0; m<check.size(); m++)
                {
                    res.push_back(check[m]);
                    cout << i << ":" << check[m] << ":" << res.size() << "\n";
                    if (res.size() == k)
                    {
                        break;
                    }
                }
                if (res.size() == k)
                {
                    break;
                }
            }
        }
        return res;
    }
};
