class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sn{};
        unordered_set<int> sc{};
        int res = 0;

        for (int i=0; i<nums.size(); i++) {
            sn.insert(nums[i]);
        }

        for (int i=0; i<nums.size(); i++) {
            if (sc.contains(nums[i])){
                // we already checked this sequence
                continue;
            } else if (sn.contains(nums[i] - 1)){
                // this is not the start of the sequence
                continue;
            } else {
                // this is the start of the sequence 
                // that we have not checked
                int checking = nums[i];
                int temp = 0;
                while (sn.contains(checking)){
                    temp++;
                    checking++;
                }
                res = max(res, temp);
            }
        }

        return res;
    }
};
