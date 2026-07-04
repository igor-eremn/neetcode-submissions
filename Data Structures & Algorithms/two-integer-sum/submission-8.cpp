class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map{};
        std::vector<int> res{};

        for (int i=0; i<nums.size(); i++)
        {
            map[target - nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i++)
        {
            if(map.contains(nums[i]) && map.at(nums[i]) != i)
            {
                res.push_back(i);
                res.push_back(map.at(nums[i]));
                break;
            }
        }

        return res;
    }
};
