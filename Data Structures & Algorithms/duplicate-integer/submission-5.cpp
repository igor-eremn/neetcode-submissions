class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> set = {};

        for (int i=0; i<nums.size(); i++)
        {
            if (!set.contains(nums[i]))
            {
                set.insert(nums[i]);
            }
            else 
            {
                return true;
            }
        }

        return false;
    }
};