#include <iostream>
using namespace std;

/**
 * Calculates the factorial of a given number.
 *
 * @param n The number for which factorial is to be calculated.
 * upper_bound of @param n ≈ 1000 
 * @param m The modulus value (default is 1e9+7).
 * @return The factorial of the given number.
 */
int factorial(int n, int m = 1e9+7) { 
    if (n==0) {return 1;}
    else {
        return (1LL * n%m * factorial(n-1)%m)%m;
    }
}


int main() {
    // code here
    int n;
    cout << "enter a number: ";
    cin >> n;
    cout << n << "! = " << factorial(n) << (n>12 ? " 1e9+7" : "");
    
    return 0;
}