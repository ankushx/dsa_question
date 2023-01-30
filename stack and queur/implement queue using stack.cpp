class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty())
        {
           // int temp=st1.top();
            st2.push(st1.top());
            st1.pop();
        }
        int tem=st2.top();
        st2.pop();
        while(!st2.empty())
        {
             st1.push(st2.top());
            st2.pop();
        }
        return tem;
    }
    
    int peek() {
        while(!st1.empty())
        {
           // int temp=st1.top();
            st2.push(st1.top());
            st1.pop();
        }
        int tem=st2.top();
          while(!st2.empty())
        {
             st1.push(st2.top());
            st2.pop();
        }
        return tem;
        return tem;
    }
    
    bool empty() {
        return st1.empty();
    }
};
