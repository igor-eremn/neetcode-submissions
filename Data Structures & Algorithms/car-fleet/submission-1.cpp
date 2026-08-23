class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> tups{};
        vector<double> res{};

        for (int i=0; i<position.size(); i++){
            tups.push_back({position[i], speed[i]});
        }

        sort(tups.begin(), tups.end());
        
        for (int i=tups.size() - 1; i>=0; i--) {
            double time = (double)(target - tups[i][0]) / tups[i][1];
            if (res.size() == 0){
                cout << time << "\n";
                res.push_back(time);
            } else {
                double temp = res.back();
                cout << time << ":" << temp << "\n";
                if (temp < time){
                    res.push_back(time);
                }
            }
        }


        return res.size();
    }
};
