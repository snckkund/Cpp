#include <iostream>
using namespace std;

class Animal {
public:
    int age;
    int weight;

    void bark() {
        cout << "barking" << endl;
    }

};

class Human {
public:
    void speak() {
        cout << "speaking" << endl;
    }
};

// multiple inheritance
class Hybrid: public Animal, public Human {

};

int main() {
    
    Hybrid h;
    h.bark();
    h.speak();

    return 0;
}