#include <iostream>
#include <cmath>

using namespace std;

int main() {

    // A  B  C  D  1  D  C  B  A
    // B  C  D  2  X  2  D  C  B
    // C  D  3  X  X  X  3  D  C
    // D  4  X  X  X  X  X  4  D
    // 5  x  x  x  x  x  x  x  5
    // D  4  X  X  X  X  X  4  D
    // C  D  3  X  X  X  3  D  C
    // B  C  D  2  X  2  D  C  B
    // A  B  C  D  1  D  C  B  A

    // 1,1
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1,k=i;
    //     while (j < (n-i+1)) {
    //         char ch='A'+k-1;
    //         cout << " " << ch << " ";
    //         j=j+1;
    //         k=k+1;
    //     }
    //     while (i) {
    //         cout << " " << i << " ";
    //         break;
    //     }
    //     int l=i-1;
    //     while (l>0) {
    //         cout << " x ";
    //         l=l-1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // 1,2
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j < i) {
    //         cout << " x ";
    //         j=j+1;
    //     }
    //     while (n-i+1) {
    //         cout << " " << i << " ";
    //         break;
    //     }
    //     int k=n-1;
    //     while (k>=i) {
    //         char ch='A'+k-1;
    //         cout << " " << ch << " ";
    //         k=k-1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // 2,1
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1,k=n-i+1;
    //     while (j < i) {
    //         char ch='A'+k-1;
    //         cout << " " << ch << " ";
    //         j=j+1;
    //         k=k+1;
    //     }
    //     while (n-i+1) {
    //         cout << " " << n-i+1 << " ";
    //         break;
    //     }
    //     int l=n-i;
    //     while (l>0) {
    //         cout << " x ";
    //         l=l-1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // 2,2
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j < (n-i+1)) {
    //         cout << " x ";
    //         j=j+1;
    //     }
    //     while (i) {
    //         cout << " " << n-i+1 << " ";
    //         break;
    //     }
    //     int k=n-1;
    //     int l=i-1;
    //     while (l>0) {
    //         char ch='A'+k-1;
    //         cout << " " << ch << " ";
    //         k=k-1;
    //         l=l-1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    return 0;

}