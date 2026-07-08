class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s{};
        int res = 0;

        for (int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }

        for (int i=0; i<nums.size(); i++){
            if (!s.contains(nums[i] - 1)){
                int checking = nums[i];
                int size = 0;

                while (true){
                    size++;
                    if (s.contains(checking + 1)){
                        checking++;
                    } else {
                        break;
                    }
                }
                res = res > size ? res : size;
            }
        }

        return res;
    }
};
