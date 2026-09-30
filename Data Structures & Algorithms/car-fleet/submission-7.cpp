class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> ttc{};
        int res = 0;
        unordered_map<int,int> m{};

        for (int i=0; i<position.size(); i++) {
            m[position[i]] = speed[i];
        }

        sort(position.begin(), position.end());

        for (int i=position.size() - 1; i>=0; i--) {
            auto pos = position[i];
            auto sp = m[pos];
            auto temp_ttc = static_cast<double>(target - pos) / sp;
            
            if (ttc.size() == 0) {
                ttc.push_back(temp_ttc);
            } else {
                if (ttc.back() < temp_ttc) {
                    ttc.push_back(temp_ttc);
                }
            }
        }

        return ttc.size();
    }
};
