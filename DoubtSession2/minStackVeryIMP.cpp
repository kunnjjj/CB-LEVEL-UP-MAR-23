class MinStack {
public:
    long long cur_min;
    stack<long long> st;
    MinStack() {
        cur_min=(long long)1e12;
    }
    
    void push(int val) {
        if(val < cur_min) // ENCRYPTION
        {   
            // push=2*newMin-oldMin
            long long toPush=2LL*val-cur_min;
            cur_min=val;
            st.push(toPush);
        }
        else
        {
            st.push(val);
        }
    }
    
    void pop() {
        // is step encryption lagaya tha, ya nahi 
        if(st.top() < cur_min) // DECRYPTION
        {
            long long pushed=st.top();
            long long newMinAtThatTime=cur_min;
            long long oldAtThatTime=2LL* newMinAtThatTime - pushed;
            cur_min=oldAtThatTime;
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < cur_min) // agar yaha encryption lagaya tha toh,curMin is at top
        {
            return cur_min;
        }
        else
        {
            return st.top();
        }
    }
    
    int getMin() {
        return cur_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */