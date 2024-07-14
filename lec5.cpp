#include <iostream>
#include <cstdio>
#include <math.h>
#include <typeinfo>

using namespace std;

// // leetcode problem #1281
// class Solution {
// public:
//     int subtractProductAndSum(int n) {
//         int sum=0, prod=1;
//         while (n!=0) {
//             int k=n%10;
//             sum=sum+k;
//             prod=prod*k;

//             n=n/10;
//         }
//         return prod-sum;
//     }
// };

// // leetcode problem #191
// class Solution {
// public:
//     int hammingWeight(int n) {
//         int count=0;
//         for (; n>=1; n=n/2) {
//             if (n%2==0) {
//                 continue;
//             } else {
//                 count++;
//             }
//         }
//         return count;
//     }
// };

int main() {

    // // leetcode problems instance of class
    // int n;
    // cin >> n;
    // Solution obj;
    // cout << obj.subtractProductAndSum(n); // - 1
    // cout << obj.hammingWeight(n); // - 2

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

    // // prime check using for loop n>2
    // int n;
    // cout << "enter n: ";
    // cin >> n;
    // bool isPrime=false;
    // for (int i=2; i < n; i++) {
    //     if (n%i==0) {
    //         isPrime=false;
    //         break;
    //     } else {
    //         isPrime=true;
    //         continue;
    //     }
    // }
    // if (isPrime) {
    //     cout << "Prime";
    // } else {
    //     cout << "Not-Prime";
    // }

    // // decimal to binary for n>1
    // cout << "enter a decimal: ";
    // int decimal;
    // string binary="";
    // cin >> decimal;
    // for (; decimal!=0; decimal=decimal/2) {
    //     binary=to_string(decimal%2)+binary;
    // }
    // cout << binary;

    // // binary to decimal
    // cout << "enter a binary: ";
    // string binary;
    // cin >> binary;
    // int decimal=0,n=binary.length();
    // for (int i=0; i<n; i++) {
    //     int k = (binary[i] - '0') * pow(2, n - i - 1);
    //     decimal=decimal+k;
    // }
    // cout << decimal;

    return 0;
}
