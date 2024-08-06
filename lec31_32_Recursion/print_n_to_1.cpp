#include <iostream>
using namespace std;

/**
 * Prints the numbers from n to 1 (tail recursion).
 *
 * @param n The starting number.
 */
void print(int n) {
    if (n==0) {return;}

    cout << n << endl;

    print(n-1); // tail recursion
}
/**
 * Prints the numbers from 1 to n (head recursion).
 *
 * @param n The number to start printing from.
 */
// void print(int n) {
//     if (n==0) {return;}
    
//     print(n-1); // head recursion 

//     cout << n << endl;
// }

int main() {
    // code here
    int n;
    cout << "enter a number: ";
    cin >> n;
    print(n);
    return 0;
}