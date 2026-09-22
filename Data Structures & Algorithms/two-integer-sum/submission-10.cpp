class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m{};
        
        vector<int> res{};

        for (int i=0; i<nums.size(); i++) {
            auto c = target - nums[i];
            if (m.find(c) != m.end()){
                res.push_back(m[c]);
                res.push_back(i);
                break;
            } else {
                m[nums[i]] = i;
            }
        }

        return res;
    }
};
