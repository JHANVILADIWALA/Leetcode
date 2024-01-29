class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>in,out;
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        peek(); //puts all element from in stack to out stack
        int val=out.top();
        out.pop();
        return val;
    }
    
    int peek() {
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
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