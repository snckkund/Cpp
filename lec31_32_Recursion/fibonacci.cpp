#include <iostream>
using namespace std;
// @Leetcode {# 509. Fibonacci number}
int fib(int n) { // 0 1 1 2 3 5 8 13 21 34 ...
    if (n == 0) {
        return 0;
    } else if (n==1) {
        return 1;
    } else {
        return fib(n-1)+fib(n-2);
        
    }
}
int main() {
    // code here
    int n;
    cout << "enter n: ";
    cin >> n;
    cout << n << "th fibonacci number is: " << fib(n);
    return 0;
}