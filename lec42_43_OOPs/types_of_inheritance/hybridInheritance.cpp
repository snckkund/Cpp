#include <iostream>
using namespace std;
// combination of more than one type of inheritance

/**
 *               [A]
 *               |  \
 *               |   \
 *               |    \
 *              [B]    [C]
 *               |
 *               |
 *               |
 *              [D]
 */

// hierarchical inheritance
class A {
public:
    void func1() {
        cout << "inside function 1" << endl;
    }
};

class B: public A{
public:
    void func2() {
        cout << "inside function 2" << endl;
    }
};

class C: public A {
public:
    void func3() {
        cout << "inside function 3" << endl;
    }
};

// multi-level inheritance
class D: public B {
public:
    void func4() {
        cout << "inside function 4" << endl;
    }
};

int main() {

    C obj1;
    obj1.func1();
    obj1.func3();

    D obj2;
    obj2.func1();
    obj2.func2();
    obj2.func4();

    return 0;
}