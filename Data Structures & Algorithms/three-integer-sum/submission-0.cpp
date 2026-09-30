class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res{};
        unordered_set<string> added{};

        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size()-2; i++) {
            int l = i + 1;
            int r = nums.size() - 1;
            int to_find = 0 - nums[i];

            while (l < r) {
                auto temp = nums[l] + nums[r];
                if (temp == to_find) {
                    auto s = to_string(nums[i]) + ":" + to_string(nums[l]) + ":" + to_string(nums[r]);
                    if (!added.contains(s)) {
                        added.insert(s);
                        res.push_back({nums[i], nums[l], nums[r]});
                    }
                    l++;
                    r--;
                } else if (temp > to_find) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return res;
    }
};
