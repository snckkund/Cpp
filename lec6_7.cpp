#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

// // leet code ques #1009
// class Solution {
// public:
//     int bitwiseComplement(int n) {
//         int m=n;
//         int mask=0;
//         if (n==0) {
//             return 1;
//         }
//         while (m!=0) {
//             mask = (mask<<1) | 1;
//             m=m>>1;
//         }
//         int ans = (~n) & mask;
//         return ans;
//     }
// };

// // leet code ques #7
// class Solution {
// public:
//     int reverse(int x) {
//         int ans = 0, digit = 0;
//         while (x != 0) {
//             digit = x % 10;
//             if (ans > INT_MAX/10 || ans < INT_MIN / 10) {
//                 ans=0;
//                 break;
//             }
//             ans = ans * 10 + digit;
//             x = x / 10;
//         }
//         return ans;
//     }
// };

// // leet code ques #231
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         for (int i=0; i<=30; i++) {
//             int ans=pow(2,i);
//             if (n == ans) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

int main() {
    
    // // leetcode problems instance of class
    // int n;
    // cin >> n;
    // Solution obj;
    // cout << obj.bitwiseComplement(n); // - 1
    // cout << obj.reverse(n); // - 2
    // cout << obj.isPowerOfTwo(n); // - 3

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

    // negative decimal number to binary {h/w}

    return 0;
}