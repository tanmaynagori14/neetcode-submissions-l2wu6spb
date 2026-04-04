class MinStack {
    stack<tuple<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push({val, val});
        else st.push({val, min(val, get<1>(st.top()))});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return get<0>(st.top());
    }
    
    int getMin() {
        return get<1>(st.top());
    }
};
