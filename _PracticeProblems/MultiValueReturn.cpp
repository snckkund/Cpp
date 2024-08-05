#include <iostream>
#include <utility> // For std::pair
#include <tuple> // For std::tuple
#include <string>
using namespace std;

// Using std::pair:
pair<int, double> getValuesP() {
    int a = 10;
    double b = 20.5;
    return make_pair(a, b);
}

// Using std::tuple:
tuple<int, double, string> getValuesT() {
    int a = 10;
    double b = 20.5;
    string c = "Hello";
    return make_tuple(a, b, c);
}

// Using a Struct:
struct Result {
    int a;
    double b;
    string c;
};

Result getValuesSt() {
    Result res;
    res.a = 10;
    res.b = 20.5;
    res.c = "Hello";
    return res;
}

// Using References:
void getValuesO(int &a, double &b, string &c) {
    a = 10;
    b = 20.5;
    c = "Hello";
}

// Using Pointers:
void getValuesPo(int *a, double *b, string *c) {
    *a = 10;
    *b = 20.5;
    *c = "Hello";
}

int main() {

    auto resultP = getValuesP(); // Using std::pair
    cout << "(pair) -> " << "First: " << resultP.first << ", Second: " << resultP.second << endl;

    auto resultT = getValuesT(); // Using std::tuple
    cout << "(tuple) -> " << "First: " << get<0>(resultT) << ", Second: " << get<1>(resultT) << ", Third: " << get<2>(resultT) << endl;
    
    Result resultSt = getValuesSt(); // Using a Struct
    cout << "(Struct) -> " << "a: " << resultSt.a << ", b: " << resultSt.b << ", c: " << resultSt.c << endl;
    
    int a;
    double b;
    string c;
    getValuesO(a, b, c); // Using References
    cout << "(References) -> " << "a: " << a << ", b: " << b << ", c: " << c << endl;

    getValuesPo(&a, &b, &c); // Using Pointers
    cout << "(Pointers) -> " << "a: " << a << ", b: " << b << ", c: " << c << endl;
    return 0;
}
