// class MinStack {
//     stack<tuple<int, int>> st;
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.empty()) st.push({val, val});
//         else st.push({val, min(val, get<1>(st.top()))});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return get<0>(st.top());
//     }
    
//     int getMin() {
//         return get<1>(st.top());
//     }
// };


class MinStack {
    // min
    // formula: int new_val = 2 * curr_val - prev_minimum
    // proof that new value is always lesser than current val value

    // Idea is that if the curr_val to insert in the stack is lesser than the prev_minimum then in the stack we insert it as new modified value (new_val) and update the min variable as the curr_val.
    // so basically min variable will contain the min value always and always containes the original values only.
    // so at the time of popping, if the min variable is smaller than the stack top element then it is definitely the modified value that is residing in the stack. So we can obtain the original value of this modified value again.
    // curr_val < prev_minimum (prev_min will be in the min variable)
    // curr_val + curr_val < prev_minimum + curr_val
    // 2 * curr_val - prev_minimum < curr_val
    // new_val < curr_val
    stack<long long> st;  // ✅ use long long
    long long min;

public:
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            min = val;
        } else {
            if(val < min) {
                long long new_val = 2LL * val - min; // ✅ prevent overflow
                st.push(new_val);
                min = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long ele = st.top();
        st.pop();

        if(ele < min) {
            long long prev_min = 2 * min - ele;
            min = prev_min;
        }
    }
    
    int top() {
        long long ele = st.top();
        if(ele < min) return min;
        return ele;
    }
    
    int getMin() {
        return min;
    }
};