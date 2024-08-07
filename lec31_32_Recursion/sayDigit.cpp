#include <iostream>
#include <vector>
using namespace std;

/**
 * @diagram: \c sayDigit.excalidraw.svg
 * Recursively prints the digits of a given number using an array of strings.
 * 
 * @param n The number whose digits are to be printed.
 * @param arr The array of strings containing the names of the digits.
 */

void sayDigit(int n, string arr[]) {
    int bit = n%10;
    if (n ==0 ) {
        return;
    } else {
        sayDigit(n/10,arr);
        cout << arr[bit] << " ";
    }
}

int main() {
    // code here
    int T, n;
    cin >> T;
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    while(T--) {
        cin >> n;
        sayDigit(n, arr);
        cout << endl;
    } 
    return 0;
}