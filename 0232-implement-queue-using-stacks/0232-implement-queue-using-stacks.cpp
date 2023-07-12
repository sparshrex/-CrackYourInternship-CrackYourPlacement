class MyQueue {
public:
    stack<int>input;
    stack<int>output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
           int x=0;
        if(!output.empty())
        {
             x= output.top();
            output.pop();
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
          x= output.top();
            output.pop();
           
        }
        return x;
        
    }
    
    int peek() {
        int x=0;
        if(!output.empty())
        {
            x = output.top();
            // output.pop();
            
            
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            x = output.top();
            // output.pop();
        }
        return x;
    
    }
    
    bool empty() {
        return input.empty()&&output.empty();
    }
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */