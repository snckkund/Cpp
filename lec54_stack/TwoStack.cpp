#include <iostream>
using namespace std;

// @Code360: Two Stacks

class TwoStack {
    int* arr;
    int top1;
    int top2;
    int size;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if (top2-top1 > 1) {
            top1++;
            arr[top1] = num;
        
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top2-top1 > 1) {
            top2--;
            arr[top2] = num;
        
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;

        } else {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;

        } else {
            return -1;
        }
    }
};

int main() {
    
    TwoStack twoStack(3);

    twoStack.push1(3); // pushing 3 in stack1.
    twoStack.push2(4); // pushing 4 in stack2.
    twoStack.push1(5); // pushing 5 in stack1.
    cout << twoStack.pop1() << endl; // popping out from stack2, it returns 5.
    cout << twoStack.pop2() << endl; // popping out from stack2, it returns 4.
    
    return 0;
}