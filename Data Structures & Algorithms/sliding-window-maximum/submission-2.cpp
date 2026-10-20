class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res{};
        deque<int> dq{};

        // we have deque (decreasing) so we can keep track of the 
        // largest element index of the current window
        
        // deque allows to pop from both front and back

        // when we find element that is great than current back,
        // we keep popping elements from the back (to maintain the decr order)
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);

            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
