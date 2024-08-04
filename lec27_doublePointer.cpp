#include <iostream>
using namespace std;

void update(int** q) { // pass by value
    // q = q + 1; // changes? - NO
    // *q = *q + 1; // changes? - YES (address stored in pointer p will change)
    **q = **q + 1; // changes? - YES (value of num will change)
}


int main() {
    // double pointer (int**)
    int num = 5;
    int* p = &num;
    int** q = &p;

    // cout << "num: " << num << " | "; // 5
    // cout << "*p: " << *p << " | "; // 5
    // cout << "**q: " << **q << endl; // 5
    // //
    // cout << "&num: " << &num << " | "; // 0x61ff0c (address of num)
    // cout << "p: " << p << " | "; // 0x61ff0c
    // cout << "*q: " << *q << endl; // 0x61ff0c
    // //
    // cout << "&p: " << &p << " | "; // 0x61ff08 (address of pointer that stores address of num)
    // cout << "q: " << q << endl; // 0x61ff08
    // //
    // cout << "&q: " << &q << endl; // 0x61ff04 (address of pointer to a pointer that stores address of num)

    cout << "==before update==" << endl;
    cout << "num: " << num << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    update(q);
    cout << "==after update==" << endl;
    cout << "num: " << num << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    
    return 0;
}