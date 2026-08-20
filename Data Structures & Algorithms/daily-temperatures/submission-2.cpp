class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        vector<int> ms{};

        for (int i=0; i<temperatures.size(); i++){
            int t = temperatures[i];
            if (ms.size() == 0 || temperatures[ms.back()] >= t){
                ms.push_back(i);
            } else {
                while (ms.size() > 0 && temperatures[ms.back()] < t){
                    int idx = ms.back();
                    res[idx] = i - idx;
                    ms.pop_back();
                }
                ms.push_back(i);
            }
        }

        return res;
    }
};
