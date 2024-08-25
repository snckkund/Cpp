#include <iostream>
#include <stack>
using namespace std;

// @Code360:

void sortedInsert(stack<int> &stack, int num) {
    // base case
    if(stack.empty() || stack.top() <= num) {
        stack.push(num);
        return;
    }

    int top = stack.top();
    stack.pop();

    // recursion
    sortedInsert(stack, num);

    stack.push(top);
}

void sortStack(stack<int> &stack)
{
    // base case
    if(stack.empty()) {
        return;
    }

    int top = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

	// back track recursive call
    sortedInsert(stack, top); 
}

void printStack(stack<int> s) {
    bool t = 1;
    while(!s.empty()) {
        cout << s.top() << (t==1?" <- Top":"") << endl;
        s.pop();
        t = 0;
    }

    cout << endl;
}

int main() {
    
    stack<int> s;
    s.push(3);
    s.push(-7);
    s.push(9);
    s.push(-2);
    s.push(5);

    cout << "original stack: " << endl;
    printStack(s);

    sortStack(s);

    cout << "sorted stack: " << endl;
    printStack(s);
    
    return 0;
}