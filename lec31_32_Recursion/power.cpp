#include <iostream>
using namespace std;

/**
 * Calculates the power of 2 raised to the given exponent.
 *
 * @param n The exponent value. Must be between 0 and 30 (inclusive).
 * @return The result of 2 raised to the power of n.
 */
int power(int n) {
    if (n==0) {return 1;}
    else {
        return (2 * power(n-1));
    }
}

int main() {
    // code here
    int n;
    cout << "enter a number: ";
    cin >> n;
    cout << "2^" << n << " = " << power(n);
    
    return 0;
}