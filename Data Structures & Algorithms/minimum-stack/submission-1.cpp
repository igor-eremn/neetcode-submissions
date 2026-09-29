class MinStack {
public:
    vector<vector<int>> ms;

    MinStack() {
        ms = {};
    }
    
    void push(int val) {
        vector<int> p{};
        if (ms.size() > 0) {
            auto t = ms.back();
            p.push_back(val);
            p.push_back(min(t[1], val));
            ms.push_back(p);
        } else {
            p.push_back(val);
            p.push_back(val);
            ms.push_back(p);
        }
    }
    
    void pop() {
        ms.pop_back();
    }
    
    int top() {
        auto t = ms.back();
        return t[0];
    }
    
    int getMin() {
        auto t = ms.back();
        return t[1];
    }
};
