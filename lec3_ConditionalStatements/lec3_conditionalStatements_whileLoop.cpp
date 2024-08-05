#include <iostream>
using namespace std;

int main() {
    // // conditional statements 
    // cout << "enter a: ";
    // int a;
    // cin >> a;
    // if (a>0) {
    //     cout << a << " is a positive number" << endl;
    // } else if (a<0) {
    //     cout << a << " is a negative number" << endl;
    // } else {
    //     cout << "a is zero"<< endl;
    // }


    // // cin.get() 
    // /* to get the space, tab, enter character from the input buffer.
    // std::cin does not take those as input.
    // takes the first "character" from the input buffer.
    // */
    // cout << "enter a number: " << endl;
    // int a;
    // a= cin.get();
    // cout<< "value of a is : " << a << endl;   


    // // find below codes output
    // int a = 9;
    // if (a == 9) {
    //     cout << "NINEY" ;
    // } if (a > 0) {
    //     cout << "POSITIVE" ;
    // } else {
    //     cout << "NEGETIVE" ;
    // }

    // int a = 2;
    // int b = a+1;
    // if ((a=3)==b){
    //     cout << a;
    // } else {
    //     cout << a+1;
    // }


    // // loops
    // // while loop
    // // to print first n numbers
    // int n;
    // cout << "enter n: ";
    // cin >> n;
    // int i = 1;
    // while (i <= n) {
    //     cout << i << " ";
    //     i=i+1;
    // }

    // // to find the sum of n numbers
    // cout << "enter a number: ";
    // int n;
    // cin >> n;
    // int i = 1;
    // int sum = 0;
    // while (i <= n) {
    //     sum = sum + i;
    //     i = i + 1;
    // }
    // cout << "sum of first " << n << " numbers is " << sum;

    // // sum of even numbers between n
    // cout << "enter n: ";
    // int n;
    // cin >> n;
    // int i = 1;
    // int sum = 0;
    // while (i <= n) {
    //     if (i%2==0) {
    //         sum = sum+i;
    //         i=i+1;
    //     } else {
    //         i=i+1;
    //     }
    // }
    // cout << "sum of even numbers between " << n << " is " << sum;


    // // celcius to fahrenheit
    // cout << "enter degree in celsius: ";
    // float c,f;
    // cin >> c;
    // f = (c*9/5)+32;
    // cout << "degree in farhenheit is: " << f << "F" << endl;


    // // using break and continue statements
    // // check prime or not prime
    // int n,q=2;
    // cout << "enter a number: ";
    // cin >> n;
    // while (q<n) {
    //     if (n%q==0) {
    //         cout << "Not prime";
    //         break;          
    //     } else {
    //         q=q+1;
    //         if (q==n) {
    //             cout << "prime";
    //         } else {
    //             continue;
    //         }        
    //     }
    // }


    // // pattern problems
    // // *  *  *  * 
    // // *  *  *  * 
    // // *  *  *  * 
    // // *  *  *  *
    // int n, i=1;
    // cout << "enter n: ";
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j <= n) {
    //         cout << " * ";
    //         j=j+1;       
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // 1  1  1  1 
    // // 2  2  2  2 
    // // 3  3  3  3 
    // // 4  4  4  4
    // int n, i=1;
    // cout << "enter n: ";
    // cin >> n;
    // while (i <= n) {
    //     int j=1;
    //     while (j <= n) {
    //         cout << " " << i << " ";
    //         j=j+1;      
    //     }
    //     cout << endl;
    //     i=i+1;
    // }
    
    // // *  *  *  * 
    // // *  *  * 
    // // *  * 
    // // * 
    // int n, i=1;
    // cout << "enter n: ";
    // cin >> n;
    // while (i <= n) {
    //     int j=i;
    //     while (j <= n) {
    //         cout << " * ";
    //         j=j+1;       
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // // 1  2  3  4 
    // // 2  3  4 
    // // 3  4 
    // // 4 
    // int n, i=1;
    // cout << "enter n: ";
    // cin >> n;
    // while (i <= n) {
    //     int j=i;
    //     while (j <= n) {
    //         cout << " " << j << " ";
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    return 0;

}
