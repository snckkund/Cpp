#include <iostream>
using namespace std;

int main() {

    // int num = 5;
    // cout << "num: " << num << endl;
    //
    // // address of operator - &
    // cout << "address of num is: " << &num << endl;
    //
    // // initializing a pointer - *
    // int *ptr = &num;
    //
    // cout << "value is: " << *ptr << endl;
    // cout << "points to address: " << ptr << endl;
    //
    // double d = 4.3;
    // double *p2 = &d;
    // cout << "points to address: " << p2 << endl;
    // cout << "value is: " << *p2 << endl;
    //
    // cout << "size of integer is: " << sizeof(num) << endl;
    // cout << "size of pointer is: " << sizeof(ptr) << endl; // stores address. in some machines its 8, in some its 4
    
    // int i = 5;
    // int *p = 0;
    // p = &i;
    // cout << p << endl;
    // cout << *p << endl;

    // int n = 5;
    // int a = n;
    // a++;
    // cout << a << " " << n << endl;
    //
    // int *p = &n;
    // cout << n << endl;
    // (*p)++;
    // cout << n << endl;
    //
    // // copying a pointer
    // int *q = p;
    // cout << p  << " - " << q << endl;
    // cout << *p << " - " << *q << endl;

    // int i = 3;
    // int *t = &i;
    //
    // cout << t << " " << *t << endl; // 0x61ff08 3
    //
    // *t++; // changes address stored in t
    // cout << t << " " << *t << endl; // 0x61ff0c 6422284
    //
    // (*t)++; // changes value at address i;
    // cout << t << " " << *t << endl; // 0x61ff08 4
    //
    // t++; // incements address stored in t by 4 (incase of int)
    // cout << t << " " << *t << endl; // 0x61ff0c 6422284

    return 0;
}