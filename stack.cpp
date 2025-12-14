#include <iostream>
#include <string>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int val) {
        if (!isFull()) {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (!isEmpty()) {
            int val = arr[top];
            top--;
            return val;
        }
        return -1;
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return -1;
    }
};

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string exp) {
    Stack s;
    string result = "";
    
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (c == ' ') continue;
        
        if (c >= '0' && c <= '9') {
            result += c;
            result += ' ';
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (s.peek() != '(') {
                result += (char)s.pop();
                result += ' ';
            }
            s.pop();
        }
        else {
            while (!s.isEmpty() && s.peek() != '(' && 
                   precedence((char)s.peek()) >= precedence(c)) {
                result += (char)s.pop();
                result += ' ';
            }
            s.push(c);
        }
    }
    
    while (!s.isEmpty()) {
        result += (char)s.pop();
        result += ' ';
    }
    
    if (result.back() == ' ') {
        result.pop_back();
    }
    
    return result;
}

int evaluatePostfix(string exp) {
    Stack s;
    
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (c == ' ') continue;
        
        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        }
        else {
            int b = s.pop();
            int a = s.pop();
            
            if (c == '+') s.push(a + b);
            else if (c == '-') s.push(a - b);
            else if (c == '*') s.push(a * b);
            else if (c == '/') s.push(a / b);
        }
    }
    
    return s.pop();
}

int main() {
    string exp;
    
    cout << "Enter expression: ";
    getline(cin, exp);
    
    string postfix = infixToPostfix(exp);
    cout << "Postfix: " << postfix << endl;
    
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    
    return 0;
}
