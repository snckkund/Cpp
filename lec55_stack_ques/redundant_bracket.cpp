#include <iostream>
#include <stack>
using namespace std;

// @Code360: Redundant Brackets

bool findRedundantBrackets(string &s)
{   
    stack<char> st;
    for (char ch:s) {

        // if opening bracket or operation, push

        if ((ch == '(') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')) {
            st.push(ch);
        }

        // if closing bracket, check for operation and pop
        else {
            if (ch == ')') {
                bool redundant = true;
                while (st.top() != '(') {
                    char top = st.top();
                    if((top == '+') || (top == '-') || (top == '*') || (top == '/')) {
                        redundant = false;
                    }
                    st.pop(); 
                }

                if (redundant == true) {
                    return true;
                }

                st.pop();
            }
        }
    }

    return false;
}

int main() {
    
    string s = "(a*b+(c/d))";

    cout << "redundant? " << findRedundantBrackets(s) << endl;
    
    return 0;
}