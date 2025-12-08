










class MyQueue {
public:
    
    stack<int> stk;
    
    MyQueue() {
        
    }
    
    void recurse(int x, stack<int> &stk){  
        if(stk.empty()){
            stk.push(x);
            return;
        }
        int current_top = stk.top();
        stk.pop();
        recurse(x, stk);
        stk.push(current_top);
    }
    
    void push(int x) {
        recurse(x, stk);
    }
    
    int pop() {
        int topValue = stk.top();
        stk.pop();
        return topValue;
    }
    
    int peek() {
        int topValue = stk.top();
        return topValue;
    }
    
    bool empty() {
        return stk.empty();
    }
};


















class MyQueue {
public:
    
    stack<int> primary, aux;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        primary.push(x);
    }
    
    int pop() { 
        int topValue = peek();
        aux.pop();
        return topValue;
    }
    
    int peek() {
        if(aux.empty()){
            while(!primary.empty()){
                int tp = primary.top();
                aux.push(tp);
                primary.pop();
            }
        }
        
        return aux.top();
    }
    
    bool empty() {
        return primary.empty() && aux.empty();
    }
};
