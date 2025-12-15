#include <iostream>
#include <string>
using namespace std;

class Stack {
    int elements[100];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 99;
    }

    void push(int value) {
        if (!isFull()) {
            topIndex++;
            elements[topIndex] = value;
        }
    }

    int pop() {
        if (!isEmpty()) {
            int value = elements[topIndex];
            topIndex--;
            return value;
        }
        return -1;
    }

    int peek() {
        if (!isEmpty()) {
            return elements[topIndex];
        }
        return -1;
    }
};

int precedence(char operatorChar) {
    if (operatorChar == '*' || operatorChar == '/') return 2;
    if (operatorChar == '+' || operatorChar == '-') return 1;
    return 0;
}

string infixToPostfix(string expression) {
    Stack stack;
    string result = "";
    
    for (int i = 0; i < expression.length(); i++) {
        char currentChar = expression[i];
        if (currentChar == ' ') continue;
        
        if (currentChar >= '0' && currentChar <= '9') {
            result += currentChar;
            result += ' ';
        }
        else if (currentChar == '(') {
            stack.push(currentChar);
        }
        else if (currentChar == ')') {
            while (stack.peek() != '(') {
                result += (char)stack.pop();
                result += ' ';
            }
            stack.pop();
        }
        else {
            while (!stack.isEmpty() && stack.peek() != '(' && 
                   precedence((char)stack.peek()) >= precedence(currentChar)) {
                result += (char)stack.pop();
                result += ' ';
            }
            stack.push(currentChar);
        }
    }
    
    while (!stack.isEmpty()) {
        result += (char)stack.pop();
        result += ' ';
    }
    
    if (result.back() == ' ') {
        result.pop_back();
    }
    
    return result;
}

int evaluatePostfix(string expression) {
    Stack stack;
    
    for (int i = 0; i < expression.length(); i++) {
        char currentChar = expression[i];
        if (currentChar == ' ') continue;
        
        if (currentChar >= '0' && currentChar <= '9') {
            stack.push(currentChar - '0');
        }
        else {
            int secondOperand = stack.pop();
            int firstOperand = stack.pop();
            
            if (currentChar == '+') stack.push(firstOperand + secondOperand);
            else if (currentChar == '-') stack.push(firstOperand - secondOperand);
            else if (currentChar == '*') stack.push(firstOperand * secondOperand);
            else if (currentChar == '/') stack.push(firstOperand / secondOperand);
        }
    }
    
    return stack.pop();
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
