












class MyStack {
public:
    queue<int> mainQueue;
    queue<int> tempQueue;
    
    MyStack() {
        
    }
    
    void push(int value) {
        while(!mainQueue.empty()){
            tempQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        mainQueue.push(value);
        while(!tempQueue.empty()){
            mainQueue.push(tempQueue.front());
            tempQueue.pop();
        }
    }
    
    int pop() {
        int topValue = mainQueue.front();
        mainQueue.pop();
        return topValue;
    }
    
    int top() {
        return mainQueue.front();
    }
    
    bool empty() {
        return mainQueue.empty();
    }
};























class MyStack {
public:
    queue<int> mainQueue;
    
    MyStack() {
        
    }
    
    void reverseQueue(queue<int> &queue){  
        if(queue.empty())
            return;
        int frontElement = queue.front();
        queue.pop();
        reverseQueue(queue);
        queue.push(frontElement);
    }
    
    void push(int value) {
        reverseQueue(mainQueue);
        mainQueue.push(value);
        reverseQueue(mainQueue);
    }
    
    int pop() {
        int topValue = mainQueue.front();
        mainQueue.pop();
        return topValue;
    }
    
    int top() {
        return mainQueue.front();
    }
    
    bool empty() {
        return mainQueue.empty();
    }
};
