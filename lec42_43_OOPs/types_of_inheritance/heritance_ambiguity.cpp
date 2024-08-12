#include <iostream>
using namespace std;

class A {
public:
    void func() {
        cout << "inside A" << endl;
    }
};

class B{
public:
    void func() {
        cout << "inside B" << endl;
    }
};

class C: public A, public B{

};

int main() {

    C obj;
    // obj.func(); // ambiguity
    obj.A::func();
    obj.B::func();
    
    return 0;
}