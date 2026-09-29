class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<vector<int>> s{};
        vector<int> res(temperatures.size(), 0);

        for (int i=0; i<temperatures.size(); i++) {
            auto t = temperatures[i];
            if (s.size() == 0){
                s.push_back({t,i});
            } else {
                auto p = s.back();
                if (p[0] >= t) {
                    s.push_back({t,i});
                } else {
                    while (p[0] < t) {
                        res[p[1]] = i - p[1];
                        s.pop_back();
                        if (s.size() > 0) {
                            p = s.back();
                        } else {
                            break;
                        };
                    }
                    s.push_back({t,i});
                }
            }
        }

        return res;
    }
};
