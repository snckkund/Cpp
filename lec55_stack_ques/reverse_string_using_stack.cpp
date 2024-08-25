#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    string str = "cpp";
    stack<char> s;

    for (char ch : str) {
        s.push(ch);
    }
    
    string ans = "";

    while(!s.empty()) {
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }
    
    cout << "ans in reverse: " << ans << endl;

    return 0;
}