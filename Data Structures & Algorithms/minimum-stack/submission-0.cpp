class MinStack {
public:
    vector<vector<int>> s{};

    MinStack() {
    }
    
    void push(int val) {
        int m{};
        if (s.size() > 0){
            m = min(val, (s.back())[1]);
        } else {
            m = val;
        }
        s.push_back({val, m});
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        vector<int> v = s.back();
        return v[0];
    }
    
    int getMin() {
        vector<int> v = s.back();
        return v[1];
    }
};
