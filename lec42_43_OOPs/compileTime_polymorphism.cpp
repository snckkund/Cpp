#include <iostream>
using namespace std;
// compile time polymorphism (static polymorphism)

// function overloading
class A {
public:
    void sayHello() {
        cout << "Hello" << endl;
    }

    void sayHello(string str) {
        cout << "Hello " << str << endl;
    }
    
    void sayHello(char ch) {
        cout << "Hello " << ch << endl;
    }

    int sayHello(string str, int n) {
        cout << "Hello " << str << " " << n << endl;
        return 1;
    }

};

//operator overloading
class B {
public:
    int a;
    int b;

    int add() {
        return a+b;
    }

    void operator+ (B &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "output: " << value2 - value1 << endl;
    }

    void operator() () {
        cout << "bracket here!!" << this->a << endl;
    }
};

int main() {
    
    // A obj;
    // obj.sayHello();
    // obj.sayHello("world");
    // obj.sayHello('A');
    // obj.sayHello("world",7);

    B obj1,obj2;
    obj1.a = 4;
    obj2.a = 7;
    obj1 + obj2;

    obj1();

    return 0;
}