class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
    }
    
    int top() {
        int val = st.top().first;
        
        return val;
    }
    
    int getMin() {
        int minVal = st.top().second;
        return minVal;
    }
};
