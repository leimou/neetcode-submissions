class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (m.empty())
        {
            m.push(val);
        }
        else if (m.top() >= val)
        {
            m.push(val);
        }
    }
    
    void pop() {
        int top = s.top();
        if (!m.empty() && m.top() == top)
        {
            m.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }

private:
    std::stack<int> s;
    std::stack<int> m;
};
