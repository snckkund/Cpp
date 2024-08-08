#include <iostream>
using namespace std;

int powerXn(int X, int n) { // O(log(n))
    if (n==0) {
        return 1;
    }

    int p = powerXn(X,n/2);
    if(n&1) {
        
        return X*p*p;
    }
    return p*p;
}

int main() {
    // Test cases for powerXn function
    cout << powerXn(2, 0) << endl;  // Expected output: 1
    cout << powerXn(2, 1) << endl;  // Expected output: 2
    cout << powerXn(3, 4) << endl;  // Expected output: 81
    cout << powerXn(5, 3) << endl;  // Expected output: 125
    cout << powerXn(-3, 3) << endl;  // Expected output: -27
    cout << powerXn(-1, 5) << endl;  // Expected output: -1
    cout << powerXn(-2, 4) << endl;  // Expected output: 16
    cout << powerXn(0, 0) << endl;  // Expected output: 1
    
    return 0;
}