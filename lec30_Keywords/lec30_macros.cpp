/*
Macros, Global Variables, Inline Functions & Default Args
*/
#include <iostream>
using namespace std;

#define  PI  3.1416 // creating a macro
#define  AREA(r)  (PI*(r)*(r)) // function-like macro

int main() {
    // int r = 5;
    // // int pi = 3.14;
    // double area = PI * r * r;
    // cout << "area of circle with radius " << r << " is: " << area << endl;
    //
    cout << "area: " << AREA(5);

    return 0;
}