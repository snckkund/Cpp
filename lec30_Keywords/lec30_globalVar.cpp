#include <iostream>
using namespace std;

int n = 15; // creating global variable

void a() {
    cout << "inside a(): " << n << endl;
}

void b() {
    cout << "inside b(): " << n << endl;
}

int main() {

    cout << "inside main(): " << n << endl;
    a();
    b();
    
    return 0;
}