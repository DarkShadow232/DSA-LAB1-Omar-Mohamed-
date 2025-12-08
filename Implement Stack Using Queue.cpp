












class MyStack {
public:
    
    queue<int> primary;
    queue<int> auxiliary;
    
    MyStack() {
        
    }
    
    void push(int x) {
        while(!primary.empty()){
            auxiliary.push(primary.front());
            primary.pop();
        }
        primary.push(x);
        while(!auxiliary.empty()){
            primary.push(auxiliary.front());
            auxiliary.pop();
        }
    }
    
    int pop() {
        int top = primary.front();
        primary.pop();
        return top;
    }
    
    int top() {
        return primary.front();
    }
    
    bool empty() {
        return primary.empty();
    }
};























class MyStack {
public:
    
    queue<int> que;
    
    MyStack() {
        
    }
    
    void reverseRecursively(queue<int> &que){  
        if(que.empty())
            return;
        int current_top = que.front();
        que.pop();
        reverseRecursively(que);
        que.push(current_top);
    }
    
    void push(int x) {
        reverseRecursively(que);
        que.push(x);
        reverseRecursively(que);
    }
    
    int pop() {
        int top = que.front();
        que.pop();
        return top;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};
