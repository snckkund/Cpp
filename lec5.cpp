#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main() {

    // // bit-wise operator
    // int a = 0b100;
    // int b = 0b110;
    // cout << (~a) << endl;
    // cout << (a&b) << endl;
    // cout << (a|b) << endl;
    // cout << (a^b) << endl;
    // cout << (a<<2) << endl;
    // cout << (b>>2) << endl;

    // // pre - post increment-decrement operator
    // int i = 7;
    // cout << i++ << endl; // 7, i=8
    // cout << ++i << endl; // 9, i=9
    // cout << i-- << endl; // 9, i=8
    // cout << --i << endl; // 7, i=7

    // // for loop
    // // fibonacci
    // int n,a=0,b=1,sum=0;
    // cout << "enter n: ";
    // cin >> n;
    // cout << a << " " << b;
    // for (int i=0; i<n; i++) {
    //     sum=a+b;
    //     a=b;
    //     b=sum;
    //     cout << " " << sum;
    // }

    // prime check using for loop n>2
    int n;
    cout << "enter n: ";
    cin >> n;
    bool isPrime=false;
    for (int i=2; i < n; i++) {
        if (n%i==0) {
            isPrime=false;
            break;
        } else {
            isPrime=true;
            continue;
        }
    }
    if (isPrime) {
        cout << "Prime";
    } else {
        cout << "Not-Prime";
    }
    
    return 0;
}