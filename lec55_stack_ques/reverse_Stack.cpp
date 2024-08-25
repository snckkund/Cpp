#include <iostream>
#include <stack>
using namespace std;

// @Code360: Reverse Stack Using Recursion

void insertAtBottom(stack<int> &stack, int num) {
    // base case
    if(stack.empty()) {
        stack.push(num);
        return;
    }

    int top = stack.top();
    stack.pop();

    // recursion
    insertAtBottom(stack, num);

    stack.push(top);
}

void reverseStack(stack<int> &stack) {
    // base case
    if(stack.empty()) {
        return;
    }

    int top = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    insertAtBottom(stack, top); 
}

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
}

int main() {
    
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    printStack(s);

    reverseStack(s);

    printStack(s);
    
    return 0;
}