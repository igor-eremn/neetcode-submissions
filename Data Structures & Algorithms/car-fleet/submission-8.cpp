class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> ttc{};
        unordered_map<int,int> m{};

        // create a map of position -> speed, so we can sort positions
        for (int i=0; i<position.size(); i++) {
            m[position[i]] = speed[i];
        }

        sort(position.begin(), position.end());

        // start checking from the end (as there is nothing in front of the first car)
        // ttc keeps track of time to complete for the fleet
        // when we check new car and its ttc <= of the previous stack, then
        // that car will join existing fleet, if not, it will create 
        // its own fleet with cars behind it
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
