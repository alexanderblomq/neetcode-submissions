class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        if(minimum.empty() || val <= minimum.top()) {
            minimum.push(val);
        }
    }
    
    void pop() {
        if(values.top() == minimum.top()) {
            minimum.pop();
        }
        values.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return minimum.top();
    }
private:
    stack<int> minimum;
    stack<int> values;
};
