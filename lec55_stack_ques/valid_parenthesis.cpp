#include <iostream>
#include <stack>
using namespace std;

// Code360:  Valid Parentheses

bool isValidParenthesis(string s)
{   
    stack<char> st;
    for (char ch:s) {

        // if opening bracket, push
        // if closing bracket, compare top and pop if it matches the corresponding opening bracket

        if ((ch == '(') || (ch == '{') || (ch == '[')) {
            st.push(ch);
        }

        else {
            if (!st.empty()) {
                char top = st.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                    st.pop();
                }

                else {
                    return false;
                }

            }

            else {
                return false;
            }
        }
    }

    if (st.empty()) {
        return true;
    }

    else {
        return false;
    }

}

int main() {
    
    string s ="[[}[";

    if (isValidParenthesis(s)) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;

    }
    
    return 0;
}