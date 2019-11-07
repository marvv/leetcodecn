class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
      
    }
    
    void push(int x) {
        d.push_back(x);
        m[x] = m[x] + 1;
    }
    
    void pop() {
        if (d.empty()) {
            return ;
        }
        
        int x = d[d.size()-1];
        d.resize(d.size()-1);
        m[x] = m[x] -1;
        if (m[x] <= 0) {
            m.erase(x);
        }
    }
    
    int top() {
        if (d.empty()) return -1;
        return d[d.size()-1];
    }
    
    int getMin() {
        if (d.empty()) return -1;
        return m.begin()->first;
    }
    
    vector<int> d;
    map<int, int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */