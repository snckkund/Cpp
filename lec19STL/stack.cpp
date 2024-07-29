#include <iostream>
#include <stack>
using namespace std;

int main() {
    // code here
    stack<string> s;
    s.push("abc");
    s.push("pqr");
    s.push("xyz");

    cout << "top -> " << s.top() << endl;

    s.pop();

    cout << "top -> " << s.top() << endl;

    cout << "size of stack: " << s.size() << endl;
    cout << "empty?: " << s.empty() << endl;

    return 0;
}