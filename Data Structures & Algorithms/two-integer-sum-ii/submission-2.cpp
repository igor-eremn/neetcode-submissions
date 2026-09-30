class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        bool found = false;

        while (!found) {
            auto temp = numbers[l] + numbers[r];
            if (temp == target) {
                found = true;
            } else if (temp < target) {
                l++;
            } else {
                r--;
            }
        }

        return {l + 1, r + 1};
    }
};
