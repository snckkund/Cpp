#include <iostream>
using namespace std;

int main() {
    // // continution of the pattern problems
    // // 1  2  3  4 
    // // 1  2  3  4 
    // // 1  2  3  4 
    // // 1  2  3  4 
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //   int j = 1;
    //   while (j <= n) {
    //     cout << " " << j << " ";
    //     j = j + 1;
    //   }
    //   cout << endl;
    //   i = i + 1;
    // }

    // // 4  3  2  1 
    // // 4  3  2  1 
    // // 4  3  2  1 
    // // 4  3  2  1 
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while(i <= n) {
    //   int j = n;
    //   while (j >= 1) {
    //     cout << " " << j << " ";
    //     j=j-1;
    //   }
    //   cout << endl;
    //   i=i+1;
    // }

    // // 1  2  3 
    // // 4  5  6 
    // // 7  8  9 
    // cout << "enter n: ";
    // int n, i=1, j=1;
    // cin >> n;
    // while (i <= n) {
    //     int k = 1;
    //     while (k <= n) {
    //         cout << " " << j << " ";
    //         j=j+1;
    //         k=k+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // *
    // // *  *
    // // *  *  *
    // // *  *  *  *
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j = 1;
    //     while (j <= i) {
    //         cout << " * ";
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // 1
    // // 1  2
    // // 1  2  3
    // // 1  2  3  4
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j = 1;
    //     while (j <= i) {
    //         cout << " " << j << " ";
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // 1
    // // 2  2
    // // 3  3  3
    // // 4  4  4  4
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j = 1;
    //     while (j <= i) {
    //         cout << " " << i << " ";
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // 1 
    // // 2  3
    // // 4  5  6
    // // 7  8  9  10
    // cout << "enter n: ";
    // int n, i=1, k=1;
    // cin >> n;
    // while (i <= n) {
    //     int j = 1;
    //     while (j <= i) {
    //         cout << " " << k << " ";
    //         k=k+1;
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // 1 
    // // 2  3
    // // 3  4  5
    // // 4  5  6  7
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1, k = i;
    //     while (j <= i) {
    //         cout << " " << k << " ";
    //         k=k+1;
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // 1
    // // 2  1
    // // 3  2  1
    // // 4  3  2  1
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=i;
    //     while (j > 0) {
    //         cout << " " << j << " ";
    //         j=j-1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // A  A  A
    // // B  B  B
    // // C  C  C
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j <= n) {
    //         cout << " " << char(i+64) << " ";
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // A  B  C
    // // A  B  C
    // // A  B  C
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j <= n) {
    //         cout << " " << char(j+64) << " ";
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // A  B  C
    // // D  E  F
    // // G  H  I
    // cout << "enter n: ";
    // int n, i=1, k=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j <= n) {
    //         cout << " " << char(k+64) << " ";
    //         k=k+1;
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // D 
    // // D  C
    // // D  C  B
    // // D  C  B  A
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j <= i) {
    //         cout << " " << char(n - j + 65) << " ";
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // D
    // // C  D
    // // B  C  D
    // // A  B  C  D
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     char k = 'A' + n - i;
    //     while (j <= i) {
    //         cout << " " << k << " ";
    //         k=k+1;
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // //          *
    // //       *  *
    // //    *  *  *
    // // *  *  *  *
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=i;
    //     while (j < n) {
    //         cout << "   ";
    //         j=j+1;
    //     }
    //     int k = 1;
    //     while (k <= i) {
    //         cout << " * ";
    //         k=k+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // x  x  x  x
    // // x  x  x
    // // x  x
    // // x
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j <= n-i+1) {
    //         cout << " x ";
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // x  x  x  x
    // //    x  x  x
    // //       x  x
    // //          x
    // cout << "enter n: ";
    // int n, i=1;
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j < i) {
    //         cout << "   ";
    //         j=j+1;
    //     }
    //     int k=1;
    //     while (k <= n-i+1) {
    //         cout << " x ";
    //         k=k+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    return 0;
}