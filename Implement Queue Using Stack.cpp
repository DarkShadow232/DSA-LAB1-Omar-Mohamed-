










class MyQueue {
public:
    stack<int> mainStack;
    
    MyQueue() {
        
    }
    
    void insertAtBottom(int value, stack<int> &stack){  
        if(stack.empty()){
            stack.push(value);
            return;
        }
        int topElement = stack.top();
        stack.pop();
        insertAtBottom(value, stack);
        stack.push(topElement);
    }
    
    void push(int value) {
        insertAtBottom(value, mainStack);
    }
    
    int pop() {
        int frontValue = mainStack.top();
        mainStack.pop();
        return frontValue;
    }
    
    int peek() {
        int frontValue = mainStack.top();
        return frontValue;
    }
    
    bool empty() {
        return mainStack.empty();
    }
};


















class MyQueue {
public:
    stack<int> inputStack, outputStack;
    
    MyQueue() {
        
    }
    
    void push(int value) {
        inputStack.push(value);
    }
    
    int pop() { 
        int frontValue = peek();
        outputStack.pop();
        return frontValue;
    }
    
    int peek() {
        if(outputStack.empty()){
            while(!inputStack.empty()){
                int element = inputStack.top();
                outputStack.push(element);
                inputStack.pop();
            }
        }
        
        return outputStack.top();
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
