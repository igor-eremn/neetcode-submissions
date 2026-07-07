class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> from_start(n, 1); 
        vector<int> from_end(n, 1); 

        for (int i=0; i<nums.size(); i++)
        {
            from_end.push_back(-1);
        }

        for(int i = 0; i < n; i++)
        {
            from_start[i] = nums[i] * (i > 0 ? from_start[i-1] : 1);
        }

        for(int i = n - 1; i >= 0; i--)
        {
            from_end[i] = nums[i] * (i < n - 1 ? from_end[i+1] : 1);
        }

        vector<int> res{};
        res.reserve(n);

        for(int i = 0; i < n; i++)
        {
            res.push_back((i > 0 ? from_start[i-1] : 1) * (i < n - 1 ? from_end[i+1] : 1));
        }

        return res;
    }
};
