class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res{};
        unordered_map<int,int> m{};
        vector<vector<int>> f(nums.size() + 1);

        for (int i=0; i<nums.size(); i++){
            if (m.contains(nums[i])){
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }

        for (const auto& [key,value] : m){
            f[value].push_back(key);
        }

        for (int i=f.size() - 1; i>=0; i--){
            for (int k=0; k<f[i].size(); k++){
                res.push_back(f[i][k]);
                if (res.size() == k){
                    break;
                }
            }
            if (res.size() == k){
                break;
            }
        }

        return res;
    }
};
