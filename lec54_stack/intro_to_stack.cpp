#include <iostream>
#include <stack>
using namespace std;

int main() {
    // creation of stack
    stack<int> s;

    // push oprn
    s.push(2);
    s.push(3); 

    // top of stack
    cout << "before pop, top-> " << s.top() << endl; // top is at 3

    // pop
    s.pop(); // pops out top element of stack

    cout << "after pop, top-> " << s.top() << endl;

    if(s.empty()) {
        cout << "stack is empty" << endl;

    } else {
        cout << "stack is not empty" << endl;
    }

    cout << "size of stack is: " << s.size();

    return 0;
}