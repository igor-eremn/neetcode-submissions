class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res{};

        deque<int> deq{};

        int i = 0;
        for (; i<k; i++) {
            if (deq.empty()){
                deq.push_back(nums[i]);
            } else {
                while (!deq.empty() && deq.back() < nums[i]) deq.pop_back();
                deq.push_back(nums[i]);
            }
        }
        res.push_back(deq.front());
        
        for (; i<nums.size(); i++){
            if (deq.front() == nums[i - k]) deq.pop_front();

            while (!deq.empty() && deq.back() < nums[i]) deq.pop_back();
            deq.push_back(nums[i]);
            res.push_back(deq.front());
        }

        return res;
    }
};
