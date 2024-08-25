#include <iostream>
#include <stack>
using namespace std;

// @Code360:  Insert An Element At Its Bottom In A Given Stack

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // base case
    if(myStack.empty()) {
        myStack.push(x);
        return myStack;
    }

    int temp = myStack.top();
    myStack.pop();

    // recursive call
    stack<int> ans = pushAtBottom(myStack,x);

    // back track
    ans.push(temp);

    return ans;
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
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);

    printStack(s);

    s = pushAtBottom(s,9);

    printStack(s);
    
    return 0;
}