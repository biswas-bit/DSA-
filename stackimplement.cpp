#include <iostream>
#include <string>
using namespace std;

class Stack {
    int size;
    char *arr;
    int top;

public:
    Stack(int n) {
        size = n;
        arr = new char[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char data) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = data;
    }

    char pop() {
        if (top == -1) {
            return '\0'; // return null char if empty
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Precedence function
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Infix to Postfix conversion
string infixToPostfix(string infix) {
    Stack s(infix.length());
    string postfix = "";

    for(char ch : infix) {
        if(isalnum(ch)) {
            postfix += ch;
        }
        else if(ch == '(') {
            s.push(ch);
        }
        else if(ch == ')') {
            while(!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // remove '(' from stack
        }
        else { // operator
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    // pop remaining operators
    while(!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c-d)/e";
    string postfix = infixToPostfix(infix);
    cout << "Infix:    " << infix << endl;
    cout << "Postfix:  " << postfix << endl;
    return 0;
}
