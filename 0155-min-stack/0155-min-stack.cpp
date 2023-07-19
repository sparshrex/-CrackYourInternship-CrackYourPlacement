class MinStack {
stack<long long>s;

long long mini =LONG_MAX;
public:
   
    
    void push(int val) {
     
    //  s.push(val);
	    if(s.empty())
        {
        s.push(val);
        mini = val;
        return;
        }

        if(val<mini)
        {
            s.push(((long long)2*val)-mini);
            mini = val;
        }
        else
        s.push(val);
    }
    
    void pop() {
    //    int x = s.top();
       if(s.top()<mini)
       {
        int x= s.top();
        mini = 2*mini-x;
       }
       s.pop();
    }
    
    int top() {
       if(s.top()<mini)return mini;
       return s.top();
    }
    
    int getMin() {
        return mini;
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