#include <iostream>
#include <queue>
using namespace std;

int main() {
    // code here
    queue<string> q;
    q.push("abc");
    q.push("pqr");
    q.push("xyz");

    cout << "first -> " << q.front() << " | ";
    cout << "last -> " << q.back() << endl;

    q.pop();
    cout << "first(after pop) -> " << q.front() << endl;

    cout << "size -> " << q.size();


    return 0;
}